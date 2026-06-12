// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSplineMeshComponent.h"
#include "Components/SplineMeshComponent.h"

static float SmoothStep(float A, float B, float X)
{
	if (X < A)
	{
		return 0.0f;
	}
	else if (X >= B)
	{
		return 1.0f;
	}
	const float InterpFraction = (X - A) / (B - A);
	return InterpFraction * InterpFraction * (3.0f - 2.0f * InterpFraction);
}

static FVector3f SplineEvalPos(const FVector3f& StartPos, const FVector3f& StartTangent, const FVector3f& EndPos, const FVector3f& EndTangent, float A)
{
	const float A2 = A * A;
	const float A3 = A2 * A;

	return (((2 * A3) - (3 * A2) + 1) * StartPos) + ((A3 - (2 * A2) + A) * StartTangent) + ((A3 - A2) * EndTangent) + (((-2 * A3) + (3 * A2)) * EndPos);
}

static FVector3f SplineEvalPos(const FSplineMeshParams& Params, float A)
{
	// TODO: these don't need to be doubles!
	const FVector3f StartPos = FVector3f(Params.StartPos);
	const FVector3f StartTangent = FVector3f(Params.StartTangent);
	const FVector3f EndPos = FVector3f(Params.EndPos);
	const FVector3f EndTangent = FVector3f(Params.EndTangent);

	return SplineEvalPos(StartPos, StartTangent, EndPos, EndTangent, A);
}

static FVector3f SplineEvalDir(const FVector3f& StartPos, const FVector3f& StartTangent, const FVector3f& EndPos, const FVector3f& EndTangent, float A)
{
	const FVector3f C = (6 * StartPos) + (3 * StartTangent) + (3 * EndTangent) - (6 * EndPos);
	const FVector3f D = (-6 * StartPos) - (4 * StartTangent) - (2 * EndTangent) + (6 * EndPos);
	const FVector3f E = StartTangent;

	const float A2 = A * A;

	return ((C * A2) + (D * A) + E).GetSafeNormal();
}

static FVector3f SplineEvalDir(const FSplineMeshParams& Params, float A)
{
	// TODO: these don't need to be doubles!
	const FVector3f StartPos = FVector3f(Params.StartPos);
	const FVector3f StartTangent = FVector3f(Params.StartTangent);
	const FVector3f EndPos = FVector3f(Params.EndPos);
	const FVector3f EndTangent = FVector3f(Params.EndTangent);

	return SplineEvalDir(StartPos, StartTangent, EndPos, EndTangent, A);
}

float UCustomSplineMeshComponent::getAlphaByDistanceAlongSpline(float distance)
{
	const bool bHasCustomBoundary = !FMath::IsNearlyEqual(SplineBoundaryMin, SplineBoundaryMax);

	float Alpha = 0.f;
	if (bHasCustomBoundary)
	{
		Alpha = (distance - SplineBoundaryMin) / (SplineBoundaryMax - SplineBoundaryMin);
	}
	else if (GetStaticMesh())
	{
		const FBoxSphereBounds StaticMeshBounds = GetStaticMesh()->GetBounds();
		const float MeshMinZ = GetAxisValueRef(StaticMeshBounds.Origin, ForwardAxis) - GetAxisValueRef(StaticMeshBounds.BoxExtent, ForwardAxis);
		const float MeshRangeZ = 2.0f * GetAxisValueRef(StaticMeshBounds.BoxExtent, ForwardAxis);
		if (MeshRangeZ > UE_SMALL_NUMBER)
		{
			Alpha = (distance - MeshMinZ) / MeshRangeZ;
		}
	}
	return Alpha;
}

FTransform UCustomSplineMeshComponent::CalcSliceTransformAtSplineOffset(const float Alpha) const
{

	// Apply hermite interp to Alpha if desired
	const float HermiteAlpha = bSmoothInterpRollScale ? SmoothStep(0.0, 1.0, Alpha) : Alpha;

	// Then find the point and direction of the spline at this point along
	FVector3f SplinePos = SplineEvalPos(SplineParams, Alpha);
	const FVector3f SplineDir = SplineEvalDir(SplineParams, Alpha);

	float DotProduct = FVector::DotProduct(compareVector, FVector(SplineDir.X, SplineDir.Y, SplineDir.Z));
	float RadianDelta = FMath::Acos(DotProduct);
	float DegreeDelta = FMath::RadiansToDegrees(RadianDelta);

	FVector useUpVector = SplineUpDir;

	//if more than 90 degrees, use down as "up" vector
	if (DegreeDelta > 90) {
		useUpVector = FVector::DownVector;
	}

	// Find base frenet frame
	const FVector3f BaseXVec = (FVector3f(useUpVector) ^ SplineDir).GetSafeNormal();
	const FVector3f BaseYVec = (FVector3f(SplineDir) ^ BaseXVec).GetSafeNormal();

	// Offset the spline by the desired amount
	const FVector2f SliceOffset = FMath::Lerp(FVector2f(SplineParams.StartOffset), FVector2f(SplineParams.EndOffset), HermiteAlpha);
	SplinePos += SliceOffset.X * BaseXVec;
	SplinePos += SliceOffset.Y * BaseYVec;
	 
	


	// Apply roll to frame around spline
	float UseRoll = FMath::Lerp(SplineParams.StartRoll, SplineParams.EndRoll, HermiteAlpha);
	const float CosAng = FMath::Cos(UseRoll);
	const float SinAng = FMath::Sin(UseRoll);
	const FVector3f XVec = (CosAng * BaseXVec) - (SinAng * BaseYVec);
	const FVector3f YVec = (CosAng * BaseYVec) + (SinAng * BaseXVec);

	// Find scale at this point along spline
	FVector2f UseScale = FMath::Lerp(FVector2f(SplineParams.StartScale), FVector2f(SplineParams.EndScale), HermiteAlpha);

	if (DegreeDelta > 90) {
		UseScale *= 10;
	}

	UE_LOG(LogTemp, Warning, TEXT("test"))
	DrawDebugLine(GetWorld(), FVector(SplinePos.X, SplinePos.Y, SplinePos.Z), FVector(SplinePos.X, SplinePos.Y, SplinePos.Z) + FVector::ForwardVector, FColor::Blue, true);

	// Build overall transform
	FTransform SliceTransform;
	switch (ForwardAxis)
	{
	case ESplineMeshAxis::X:
		SliceTransform = FTransform(FVector(SplineDir), FVector(XVec), FVector(YVec), FVector(SplinePos));
		SliceTransform.SetScale3D(FVector(1, UseScale.X, UseScale.Y));
		break;
	case ESplineMeshAxis::Y:
		SliceTransform = FTransform(FVector(YVec), FVector(SplineDir), FVector(XVec), FVector(SplinePos));
		SliceTransform.SetScale3D(FVector(UseScale.Y, 1, UseScale.X));
		break;
	case ESplineMeshAxis::Z:
		SliceTransform = FTransform(FVector(XVec), FVector(YVec), FVector(SplineDir), FVector(SplinePos));
		SliceTransform.SetScale3D(FVector(UseScale.X, UseScale.Y, 1));
		break;
	default:
		check(0);
		break;
	}

	return SliceTransform;

	return FTransform();

}