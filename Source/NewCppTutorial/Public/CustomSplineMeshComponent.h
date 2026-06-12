// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "CustomSplineMeshComponent.generated.h"

/**
 *
 */

UCLASS(meta = (BlueprintSpawnableComponent))
class NEWCPPTUTORIAL_API UCustomSplineMeshComponent : public USplineMeshComponent
{
	GENERATED_BODY()

	FVector compareVector{ 1, 1, 1 };


	FTransform CalcSliceTransformAtSplineOffset(const float Alpha) const;

	float getAlphaByDistanceAlongSpline(float distance);

};