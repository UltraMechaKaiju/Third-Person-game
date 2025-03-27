// Fill out your copyright notice in the Description page of Project Settings.





#include "CustomMoveComponent.h"
#include "GamePlayTagDefinitions.h"
#include "WallRunWall.h"
#include "RailGrindRails.h"
#include "Components/SplineComponent.h"

#include "XpCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"



FNetworkPredictionData_Client* UCustomMoveComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr)

		if (PawnOwner == nullptr) {
			UCustomMoveComponent* MutableThis = const_cast<UCustomMoveComponent*>(this);
			MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_Custom(*this);
			MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
			MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.f;
	}
	return ClientPredictionData;
}

UCustomMoveComponent::UCustomMoveComponent()
{
}


UCustomMoveComponent::FNetworkPredictionData_Client_Custom::FNetworkPredictionData_Client_Custom(const UCharacterMovementComponent& ClientMovement) : Super(ClientMovement)
{
}


namespace CharacterMovementConstants {
	const float VERTICAL_SLOPE_NORMAL_Z = 0.001f;
}

namespace CharacterMovementCVars {
	int32 ForceJumpPeakSubstep = 1;
	int32 UseTargetVelocityOnImpact = 1;
}

#pragma region MovementModeFunctions
void UCustomMoveComponent::SprintPressed()
{
	safe_bCanRailGrind = true;
	MaxWalkSpeed = Sprint_MaxSpeed;
}

void UCustomMoveComponent::SprintReleased()
{
	//not movement safe implementation: walk speed is not changed in the phys walk function, it is changed client side in the second line, phys walk would have to be overridden to fix this
	safe_bCanRailGrind = false;
	MaxWalkSpeed = Walk_MaxSpeed;
}

void UCustomMoveComponent::InitializeComponent()
{
	Super::InitializeComponent();
	CustomCharacterOwner = Cast<AXpCharacter>(GetOwner());
}

bool UCustomMoveComponent::IsVelocityTowardsWall(FHitResult WallToCheck)
{
	float DotCheck = FVector::DotProduct(Velocity.GetSafeNormal2D(), -(FVector(WallToCheck.Normal.X, WallToCheck.Normal.Y, 0)));
	float RadDotCheck = FMath::Acos(DotCheck);
	float DegDotCheck = FMath::RadiansToDegrees(RadDotCheck);
	if (DegDotCheck <= 90) {
		return true;
	}
	else {
		return false;
	}
}

bool UCustomMoveComponent::TryWallRun()
{
	//initial Checks
	if (!IsFalling()) return false;
	if (Velocity.SizeSquared2D() < pow(MinWallRunSpeed, 2))return false;
	//if (Velocity.Z < -MaxVerticalRunSpeed) return false;

	FHitResult WallRunWall;

#pragma region LineTraceimplementation



	FHitResult A0;
	FHitResult A1;
	FHitResult A2;
	FHitResult A3;
	FHitResult B0;
	FHitResult B1;
	FHitResult B2;
	FHitResult B3;

	TArray<FHitResult> LeftHits;
	TArray<FHitResult> RightHits;

	FVector Start = UpdatedComponent->GetComponentLocation();

	float MinDetectRadius = (2 * CapR()) / FMath::Sqrt(3.f);

	float DesiredDetectRadius = MinDetectRadius;

	FVector TraceDirection = Velocity.GetSafeNormal2D() * CapR();

	//StartingPoints
	FVector Start0L = Start + (TraceDirection * .25).RotateAngleAxis(90, FVector::DownVector);
	FVector Start0R = Start - (TraceDirection * .25).RotateAngleAxis(90, FVector::DownVector);
	FVector Start1 = Start + (TraceDirection / 2);
	FVector Start2 = Start + TraceDirection;

	//ScaleFactors
	float ScaleFactor0 = 1.5;
	float ScaleFactor2 = .86;
	float ScaleFactor1 = 1.23;
	float ScaleFactor3 = 1.35;


	//LineTrace 1A
	//Left Forward
	if (GetWorld()->LineTraceSingleByProfile(A0, Start0L, Start0L + (TraceDirection * ScaleFactor0), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) {LeftHits.Add(A0); }
	//left + 2
	if (GetWorld()->LineTraceSingleByProfile(A1, Start2, Start2 + (TraceDirection * ScaleFactor2).RotateAngleAxis(90, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { LeftHits.Add(A1); }
	//left + 1
	if (GetWorld()->LineTraceSingleByProfile(A2, Start1, Start1 + (TraceDirection * ScaleFactor1).RotateAngleAxis(90, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { LeftHits.Add(A2); }
	//left
	if (GetWorld()->LineTraceSingleByProfile(A3, Start, Start + (TraceDirection * ScaleFactor3).RotateAngleAxis(90, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { LeftHits.Add(A3); }

	if (GetWorld()->LineTraceSingleByProfile(B0, Start0R, Start0R + (TraceDirection * ScaleFactor0), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { RightHits.Add(B0); }
	if (GetWorld()->LineTraceSingleByProfile(B1, Start1, Start1 + (TraceDirection * ScaleFactor1).RotateAngleAxis(270, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { RightHits.Add(B1); }
	//Right
	if (GetWorld()->LineTraceSingleByProfile(B2, Start2, Start2 + (TraceDirection * ScaleFactor2).RotateAngleAxis(270, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { RightHits.Add(B2); }
	if (GetWorld()->LineTraceSingleByProfile(B3, Start, Start + (TraceDirection * ScaleFactor3).RotateAngleAxis(270, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { RightHits.Add(B3); }

	//if (WallRunLineTraceLength > 57) { UE_LOG(LogTemp, Warning, TEXT("Line Trace Length Error")); }


	//debug lines
	DrawDebugLine(GetWorld(), Start0L, Start0L + (TraceDirection * ScaleFactor0), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start2, Start2 + (TraceDirection * ScaleFactor2).RotateAngleAxis(90, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start1, Start1 + (TraceDirection * ScaleFactor1).RotateAngleAxis(90, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start, Start + (TraceDirection * ScaleFactor3).RotateAngleAxis(90, FVector::DownVector), FColor::Red, false, 1 / 60, 10);

	DrawDebugLine(GetWorld(), Start0R, Start0R + (TraceDirection * ScaleFactor0), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start1, Start1 + (TraceDirection * ScaleFactor1).RotateAngleAxis(270, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start2, Start2 + (TraceDirection * ScaleFactor2).RotateAngleAxis(270, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start, Start + (TraceDirection * ScaleFactor3).RotateAngleAxis(270, FVector::DownVector), FColor::Red, false, 1 / 60, 10);



	//FindOut HowThis Works
	LeftHits.Sort([](const FHitResult& LTraceHitResult, const FHitResult& RTraceHitResult) { return LTraceHitResult.Distance < RTraceHitResult.Distance; });
	RightHits.Sort([](const FHitResult& LTraceHitResult, const FHitResult& RTraceHitResult) { return LTraceHitResult.Distance < RTraceHitResult.Distance; });

	//Rather Thn Do this just check if the hit aactor is a wall run object in the future
	int LeftChosenWallIndexNumber;
	int RightChosenWallIndexNumber;
	bool FinalWallDetected = false;
	bool LeftWallDetected = false;
	bool RightWallDetected = false;


	//sort both arrays and chose the best result from each
	if (!LeftHits.IsEmpty()) {
		//UE_LOG(LogTemp, Warning, TEXT("not empty"))
		for (size_t i = 0; i < LeftHits.Num(); i++) {
			if (!LeftHits[i].Normal.IsNearlyZero()/*, Cast<AWallRunWall>(RightHits[i].Component)*/) {
				float DotCheck = FVector::DotProduct(Velocity.GetSafeNormal2D(), -(FVector(LeftHits[i].Normal.X, LeftHits[i].Normal.Y, 0)));
				float RadDotCheck = FMath::Acos(DotCheck);
				float DegDotCheck = FMath::RadiansToDegrees(RadDotCheck);
				if (DegDotCheck <= 90) {
					LeftChosenWallIndexNumber = i;
					LeftWallDetected = true;
				}
			}
		}
	}
	if (!RightHits.IsEmpty()) {
		//UE_LOG(LogTemp, Warning, TEXT("not empty"))
		for (size_t i = 0; i < RightHits.Num(); i++) {
			if (!RightHits[i].Normal.IsNearlyZero()/*, Cast<AWallRunWall>(RightHits[i].Component)*/) {
				float DotCheck = FVector::DotProduct(Velocity.GetSafeNormal2D(), -(FVector(RightHits[i].Normal.X, RightHits[i].Normal.Y, 0)));
				float RadDotCheck = FMath::Acos(DotCheck);
				float DegDotCheck = FMath::RadiansToDegrees(RadDotCheck);
				if (DegDotCheck <= 90) {
					RightChosenWallIndexNumber = i;
					RightWallDetected = true;
				}
			}
		}
	}





	//Decide between right and left

	FHitResult FinalWall;

	if (RightWallDetected && LeftWallDetected) {
		if (RightHits[RightChosenWallIndexNumber].Distance < LeftHits[LeftChosenWallIndexNumber].Distance) {
			FinalWall = RightHits[RightChosenWallIndexNumber];
			FinalWallDetected = true;
			safe_bWallRunRight = true;
		}
		else {
			FinalWall = LeftHits[LeftChosenWallIndexNumber];
			safe_bWallRunRight = false;
			FinalWallDetected = true;
		}
	}
	else if (RightWallDetected) {
		FinalWall = RightHits[RightChosenWallIndexNumber];
		safe_bWallRunRight = true;
		FinalWallDetected = true;
	}
	else if (LeftWallDetected) {
		FinalWall = LeftHits[LeftChosenWallIndexNumber];
		safe_bWallRunRight = false;
		FinalWallDetected = true;
	}
	else {
		FinalWallDetected = false;
		return false;
	}

	FVector Bug2Start = UpdatedComponent->GetComponentLocation();
	FVector Bug2CastDelta = FinalWall.Normal.GetSafeNormal2D() * CapR() * 2;
	FVector Bug2End = Bug2Start - Bug2CastDelta;
	auto Params = CustomCharacterOwner->GetIgnoreCharacterParams();
	FHitResult Bug2Test;

	GetWorld()->LineTraceSingleByProfile(Bug2Test, Bug2Start, Bug2End, "BlockAll", Params);
	DrawDebugLine(GetWorld(), Bug2Start, Bug2End, FColor::Blue, true);

	if (!Bug2Test.IsValidBlockingHit()) {
		UE_LOG(LogTemp, Warning, TEXT("Bug2 Prevented"))
			return false;
	}



	if (FinalWallDetected) {
		WallRunWall = FinalWall;

		//if (WallRunWall.Distance == A1.Distance || WallRunWall.Distance == B3.Distance) { UE_LOG(LogTemp, Warning, TEXT("A1/B3")); }
		//if (WallRunWall.Distance == A2.Distance || WallRunWall.Distance == B2.Distance) { UE_LOG(LogTemp, Warning, TEXT("A2/B2")); }
	}
	else { return false; }
	// Passed all conditions



#pragma endregion


#pragma region Sweepimplementation

/*

	FHitResult RightScan;
	FHitResult LeftScan;
	FCollisionShape StructureCollision;
	StructureCollision = CustomCharacterOwner->GetWallRunScanMesh();
	FVector End = Velocity.GetSafeNormal2D().RotateAngleAxis(90, UpdatedComponent->GetUpVector()) * WallRunScanDistance;

	GetWorld()->SweepSingleByProfile(RightScan, UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + End, UpdatedComponent->GetComponentQuat(), "BlockAll", StructureCollision, CustomCharacterOwner->GetIgnoreCharacterParams());
	GetWorld()->SweepSingleByProfile(LeftScan, UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() - End, UpdatedComponent->GetComponentQuat(), "BlockAll", StructureCollision, CustomCharacterOwner->GetIgnoreCharacterParams());

	DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + End , FColor::Purple, true, 0, 0);



	if ((RightScan.IsValidBlockingHit() && IsVelocityTowardsWall(RightScan))|| (LeftScan.IsValidBlockingHit()) && IsVelocityTowardsWall(LeftScan)){
		if ((RightScan.IsValidBlockingHit() && IsVelocityTowardsWall(RightScan)) && (LeftScan.IsValidBlockingHit()) && IsVelocityTowardsWall(LeftScan)){
			if (RightScan.Distance > LeftScan.Distance) {
					WallRunWall = LeftScan;
					safe_bWallRunRight = false;
			}
			else{
				WallRunWall = RightScan;
				safe_bWallRunRight = true;
			}
		}
		else if (RightScan.IsValidBlockingHit()) {
				WallRunWall = RightScan;
				safe_bWallRunRight = true;
		}
		else{
				WallRunWall = LeftScan;
				safe_bWallRunRight = false;
		}
	}
	else {
		return false;
	}



	if ((RightScan.Normal == FVector(0,0,0)) && (LeftScan.Normal == FVector(0, 0, 0))) { UE_LOG(LogTemp, Warning, TEXT("Should not have gotten through A")) }
	if ((WallRunWall.Normal == FVector(0, 0, 0))) { UE_LOG(LogTemp, Warning, TEXT("Should not have gotten through")); return false; }

	*/

#pragma endregion
	//set direction

	//check if set velocity passes checks
	//if (SpeedCheck()) return false;
	//Velocity.Z = FMath::Clamp(Velocity.Z, 0.f, MaxVerticalRunSpeed);

	//if (WallRunWall.Normal == FVector(0, 0, 0)) { UE_LOG(LogTemp, Warning, TEXT(" No Wall Passes")); return false; }


	if (safe_bWallRunRight) {
		Velocity = WallRunWall.Normal.RotateAngleAxis(90, FVector::UpVector);
		DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + WallRunWall.Normal * 500, FColor::Yellow, true, 1, 12);
		if (Velocity == FVector(0, 0, 0)) { UE_LOG(LogTemp, Warning, TEXT(" Try Bug")) }
	}
	else {
		Velocity = WallRunWall.Normal.RotateAngleAxis(270, FVector::UpVector);
		DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + WallRunWall.Normal * 500, FColor::Yellow, true, 1, 12);
		if (Velocity == FVector(0, 0, 0)) { UE_LOG(LogTemp, Warning, TEXT("Try Bug")) }
	}

	//start wall running
	SetMovementMode(MOVE_Custom, CMOVE_WallRun);
	//UE_LOG(LogTemp, Warning, TEXT("Wall Run set"))
	return true;
}

bool UCustomMoveComponent::TryRailGrind(){
	if ((CustomCharacterOwner->GetRailGrindHitBoxOverlapped()).Num() >= 1.f) {
		UE_LOG(LogTemp, Warning, TEXT("Hit"));
		if (safe_bCanRailGrind) {
			return true;
		}
		else
		{
			return false;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("NoHit"));
	safe_bCanRailGrind = true;
	return false;
}



bool UCustomMoveComponent::SpeedCheck() {
	//if (Velocity.SizeSquared() < pow(MinWallRunSpeed, 2)/* || Velocity.Z < -MaxVerticalRunSpeed*/)
	if (Velocity.IsNearlyZero())
	{
		UE_LOG(LogTemp, Warning, TEXT("Speed Exit"))
			return true;
	}
	else {
		return false;
	}
}
#pragma endregion

#pragma region utility
bool UCustomMoveComponent::IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const
{
	return MovementMode == MOVE_Custom && CustomMovementMode == InCustomMovementMode;
}

float UCustomMoveComponent::CapHH() const{
	return CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
}
float UCustomMoveComponent::CapR() const{
	return CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius();
}
#pragma endregion
#pragma region CMCFunctions
void UCustomMoveComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	//if (MovementMode = MOVE_Walking) {}
}

void UCustomMoveComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);



	if (IsWallRunning() && GetOwnerRole() == ROLE_SimulatedProxy)
	{
		FVector Start = UpdatedComponent->GetComponentLocation();
		FVector End = Start + UpdatedComponent->GetRightVector() * 34 * 2;
		auto Params = CustomCharacterOwner->GetIgnoreCharacterParams();
		FHitResult WallHit;
		safe_bWallRunRight = GetWorld()->LineTraceSingleByProfile(WallHit, Start, End, "BlockAll", Params);
	}
}

void UCustomMoveComponent::UpdateCharacterStateBeforeMovement(float DeltaSeconds)
{
	if (IsFalling() && !IsWallRunning()) {
		if (!TryWallRun()) {
			TryRailGrind();
		}
	}

	Super::UpdateCharacterStateBeforeMovement(DeltaSeconds);
}

void UCustomMoveComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	Super::PhysCustom(deltaTime, Iterations);

	switch (CustomMovementMode) {
	case CMOVE_WallRun:
		PhysWallRun(deltaTime, Iterations);
		break;
	case CMOVE_RailGrind:
		PhysRailGrind(deltaTime, Iterations);
		break;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("InvalidMovementMode"))
	}
}

FSavedMovePtr UCustomMoveComponent::FNetworkPredictionData_Client_Custom::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_Custom());
}

#pragma region Jumping
bool UCustomMoveComponent::CanAttemptJump() const
{
	return Super::CanAttemptJump() || IsWallRunning();
}

bool UCustomMoveComponent::DoJump(bool bReplayingMoves)
{
	bool bWasWallRunning = IsWallRunning();
	bool bWasRailGrinding = IsRailGrinding();
	if (Super::DoJump(bReplayingMoves)) {
		if (bWasWallRunning) {
			FVector Start = UpdatedComponent->GetComponentLocation();
			FVector CastDelta = Velocity.RotateAngleAxis(90, FVector::UpVector) * CapR() * 2;
			FVector End = safe_bWallRunRight ? Start + CastDelta : Start - CastDelta;
			auto Params = CustomCharacterOwner->GetIgnoreCharacterParams();
			FHitResult WallHit;
			GetWorld()->LineTraceSingleByProfile(WallHit, Start, End, "BlockAll", Params);

			FVector JumpDir = safe_bWallRunRight ? Velocity.GetSafeNormal().RotateAngleAxis(270, FVector::UpVector): Velocity.GetSafeNormal().RotateAngleAxis(90, FVector::UpVector);

			WallJumpOffForce = Velocity.Size();

			Velocity += JumpDir * WallJumpOffForce;

			Velocity *= WallJumpOffForce/Velocity.Size();
		}
		if (bWasRailGrinding) {
			safe_bCanRailGrind = false;
		}

		return true;
	}

	return false;
}
#pragma endregion
float UCustomMoveComponent::GetMaxSpeed() const
{
	if (MovementMode != MOVE_Custom) return Super::GetMaxSpeed();

	switch (CustomMovementMode)
	{
	case CMOVE_WallRun:
		return MaxWallRunSpeed;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("InvalidMovementMode"))
		return -1.f;
	}

}

float UCustomMoveComponent::GetMaxBrakingDeceleration() const {
	if (MovementMode != MOVE_Custom) return Super::GetMaxBrakingDeceleration();

	switch (CustomMovementMode)
	{
	case CMOVE_WallRun:
		return 0.f;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("InvalidMovementMode"))
		return -1.f;
	}
}

#pragma endregion

#pragma region FlagFunctions
void UCustomMoveComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	safe_bWallRunRight = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
	safe_bCanRailGrind = (Flags & FSavedMove_Character::FLAG_Custom_1) != 0;
}

bool UCustomMoveComponent::FSavedMove_Custom::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const
{
	FSavedMove_Custom* NewSavedMove = static_cast<FSavedMove_Custom*>(NewMove.Get());

	if (saved_bCanRailGrind != NewSavedMove->saved_bCanRailGrind || Saved_bWallRunRight != NewSavedMove->Saved_bWallRunRight) {
		return false;
	}
	
	return Super::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

void UCustomMoveComponent::FSavedMove_Custom::Clear()
{

	FSavedMove_Character::Clear();

	saved_bCanRailGrind = 0;

	Saved_bWallRunRight = 0;
}

uint8 UCustomMoveComponent::FSavedMove_Custom::GetCompressedFlags() const
{
	uint8 Result = Super::GetCompressedFlags();

	if (saved_bCanRailGrind) Result |= FLAG_Custom_0;
	if (Saved_bWallRunRight) Result |= FLAG_Custom_1;

	return Result;
}

void UCustomMoveComponent::FSavedMove_Custom::SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
	FSavedMove_Character::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);

	UCustomMoveComponent* CharacterMovementComp = Cast<UCustomMoveComponent>(C->GetCharacterMovement());

	saved_bCanRailGrind = CharacterMovementComp->safe_bCanRailGrind;
	Saved_bWallRunRight = CharacterMovementComp->safe_bWallRunRight;
}

void UCustomMoveComponent::FSavedMove_Custom::PrepMoveFor(ACharacter* C)
{
	Super::PrepMoveFor(C);

	UCustomMoveComponent* CharacterMovementComp = Cast<UCustomMoveComponent>(C->GetCharacterMovement());

	CharacterMovementComp->safe_bCanRailGrind = saved_bCanRailGrind;
	CharacterMovementComp->safe_bWallRunRight = Saved_bWallRunRight;
}
#pragma endregion

#pragma region Unused
bool UCustomMoveComponent::TryWallRunImp1(FHitResult Storedhit)
{
	FVector Start = UpdatedComponent->GetComponentLocation();
	FVector LeftEnd = Start - UpdatedComponent->GetRightVector() * 34.f * 2;
	FVector RightEnd = Start + UpdatedComponent->GetRightVector() * 34.f * 2;
	auto Params = CustomCharacterOwner->GetIgnoreCharacterParams();
	FHitResult FloorHit;
	if (GetWorld()->LineTraceSingleByProfile(FloorHit, Start, Start + FVector::DownVector * (84.f + MinWallRunHeight), "BlockAll", Params)) {
		return false;
	}

	//StartlineTraces
	// 
	//left cast
	GetWorld()->LineTraceSingleByProfile(Storedhit, Start, LeftEnd, "BlockAll", Params);
	if (Storedhit.IsValidBlockingHit() && (Velocity | Storedhit.Normal) < 0)
	{
		safe_bWallRunRight = false;
		return true;
	}
	// Right Cast
	else
	{
		GetWorld()->LineTraceSingleByProfile(Storedhit, Start, RightEnd, "BlockAll", Params);
		if (Storedhit.IsValidBlockingHit() && (Velocity | Storedhit.Normal) < 0)
		{
			safe_bWallRunRight = true;
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool UCustomMoveComponent::TryWallRunImp2(FHitResult Storedhit)
{
	//OutHits
	FHitResult A1;
	FHitResult A2;
	//FHitResult A3;
	//FHitResult B1;
	FHitResult B2;
	FHitResult B3;

	TArray<FHitResult> distances;

	FVector Start = UpdatedComponent->GetComponentLocation();

	FVector TraceDirection = Velocity.GetSafeNormal2D() * WallRunLineTraceLength;



	//LineTrace 1A
	if (GetWorld()->LineTraceSingleByProfile(A1, Start, Start + TraceDirection.RotateAngleAxis(30, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { distances.Add(A1); }
	if (GetWorld()->LineTraceSingleByProfile(A2, Start, Start + TraceDirection.RotateAngleAxis(90, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { distances.Add(A2); }
	//if (GetWorld()->LineTraceSingleByProfile(A3, Start, Start + TraceDirection.RotateAngleAxis(150, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { distances.Add(A3); }
	//if (GetWorld()->LineTraceSingleByProfile(B1, Start, Start + TraceDirection.RotateAngleAxis(210, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { distances.Add(B1); }
	if (GetWorld()->LineTraceSingleByProfile(B2, Start, Start + TraceDirection.RotateAngleAxis(270, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { distances.Add(B2); }
	if (GetWorld()->LineTraceSingleByProfile(B3, Start, Start + TraceDirection.RotateAngleAxis(330, FVector::DownVector), "BlockAll", CustomCharacterOwner->GetIgnoreCharacterParams())) { distances.Add(B3); }

	//if (WallRunLineTraceLength > 57) { UE_LOG(LogTemp, Warning, TEXT("Line Trace Length Error")); }


	//debug lines
	DrawDebugLine(GetWorld(), Start, UpdatedComponent->GetComponentLocation() + Velocity.GetSafeNormal2D() * 100, FColor::Green, false, 1 / 60, 10, 1.25);
	DrawDebugLine(GetWorld(), Start, Start + TraceDirection.RotateAngleAxis(90, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start, Start + TraceDirection.RotateAngleAxis(30, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start, Start + TraceDirection.RotateAngleAxis(270, FVector::DownVector), FColor::Red, false, 1 / 60, 10);
	DrawDebugLine(GetWorld(), Start, Start + TraceDirection.RotateAngleAxis(330, FVector::DownVector), FColor::Red, false, 1 / 60, 10);



	//FindOut HowThis Works
	distances.Sort([](const FHitResult& LTraceHitResult, const FHitResult& RTraceHitResult) { return LTraceHitResult.Distance < RTraceHitResult.Distance; });

	//Rather Thn Do this just check if the hit aactor is a wall run object in the future
	int ChosenWallIndexNumber;
	bool WallDetected = false;

	if (!distances.IsEmpty()) {
		UE_LOG(LogTemp, Warning, TEXT("not empty"))
			for (size_t i = 0; i < distances.Num(); i++) {
				if (/*distances[i].Normal.Z == 0*/ !distances[i].Normal.IsNearlyZero()) {
					ChosenWallIndexNumber = i;
					WallDetected = true;
				}
			}
	}

	if (WallDetected) {
		Storedhit = distances[ChosenWallIndexNumber];
		//if (Storedhit.Normal == FVector(0, 0, 0)) { UE_LOG(LogTemp, Warning, TEXT("StoredHitNormalNot Valid")) }
		if (Storedhit.Distance == A1.Distance || Storedhit.Distance == A2.Distance) { safe_bWallRunRight = false; }
		else { safe_bWallRunRight = true; }
		if (Storedhit.Distance == A1.Distance || Storedhit.Distance == B3.Distance) { UE_LOG(LogTemp, Warning, TEXT("A1/B3")); }
		if (Storedhit.Distance == A2.Distance || Storedhit.Distance == B2.Distance) { UE_LOG(LogTemp, Warning, TEXT("A2/B2")); }
		return true;
	}
	return false;
}
#pragma endregion

#pragma region CustomMovementModes
void UCustomMoveComponent::PhysWallRun(float deltaTime, int32 Iterations)
{
	if (deltaTime < MIN_TICK_TIME) {
		return;
	}
	if (!CharacterOwner || (!CharacterOwner->Controller && !bRunPhysicsWithNoController && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && (CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy)))
	{
		Acceleration = FVector::ZeroVector;
		Velocity = FVector::ZeroVector;
		return;
	}

	bJustTeleported = false;
	float RemainingTime = deltaTime;

	while (RemainingTime >= MIN_TICK_TIME && (Iterations < MaxSimulationIterations) && CharacterOwner && (CharacterOwner->Controller || bRunPhysicsWithNoController || (CharacterOwner->GetLocalRole() == ROLE_SimulatedProxy))) {
		//UE_LOG(LogTemp, Warning, TEXT("Cycle ran"))
		Iterations++;
		bJustTeleported = false;
		const float timeTick = GetSimulationTimeStep(RemainingTime, Iterations);
		RemainingTime -= timeTick;
		const FVector OldLocation = UpdatedComponent->GetComponentLocation();

#pragma region LineTraceWallDetect

		

		//General Params  for line trace implementation
		float SinPullAwayAngle = FMath::Sin(FMath::DegreesToRadians(WallRunPullAwayAngle));
		FVector Start = UpdatedComponent->GetComponentLocation();
		FVector CastDelta = Velocity.GetSafeNormal().RotateAngleAxis(90, FVector::UpVector) * CapR()* 2;
		FVector End = safe_bWallRunRight ? Start + CastDelta : Start - CastDelta;
		auto Params = CustomCharacterOwner->GetIgnoreCharacterParams();
		FHitResult WallHit;

		GetWorld()->LineTraceSingleByProfile(WallHit, Start, End, "BlockAll", Params);
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, true, 0, 0);

		

#pragma endregion

#pragma region SweepWallDetect

		/*

		FHitResult WallHit;
		FCollisionShape StructureCollision;
		FVector Start = UpdatedComponent->GetComponentLocation();
		StructureCollision = CustomCharacterOwner->GetWallRunScanMesh();
		FVector CastDelta = Velocity.GetSafeNormal2D().RotateAngleAxis(90, FVector::UpVector) * WallRunScanDistance * 1.5;

		//DrawDebugLine(GetWorld(), Start,Start + CastDelta * 100, FColor::Cyan, true, 0, 0);
		//DrawDebugLine(GetWorld(), Start,Start - CastDelta * 100, FColor::Blue, true, 0, 0);
		if (safe_bWallRunRight) {
			GetWorld()->SweepSingleByProfile(WallHit, Start, Start + CastDelta, UpdatedComponent->GetComponentQuat(), "BlockAll", StructureCollision, CustomCharacterOwner->GetIgnoreCharacterParams());
		}
		else {
			GetWorld()->SweepSingleByProfile(WallHit, Start, Start - CastDelta, UpdatedComponent->GetComponentQuat(), "BlockAll", StructureCollision, CustomCharacterOwner->GetIgnoreCharacterParams());
		}
		
		*/

#pragma endregion

		FVector MoveDirection(WallHit.Normal.X, WallHit.Normal.Y, WallHit.Normal.Z);
		if (MoveDirection == FVector(0, 0, 0)) {
			UE_LOG(LogTemp, Warning, TEXT("Bug 2")); 
			Velocity.RotateAngleAxis(45, FVector::UpVector);
			SetMovementMode(MOVE_Falling); 
			StartNewPhysics(RemainingTime, Iterations);
			return;
		}
		DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + MoveDirection * 50, FColor::Blue, true);

		if (safe_bWallRunRight) {
			Velocity = MoveDirection.RotateAngleAxis(90, FVector::UpVector) * 500;
			//UE_LOG(LogTemp, Warning, TEXT("Right"))
		}
		else {
			Velocity = MoveDirection.RotateAngleAxis(270, FVector::UpVector) * 500;
			//UE_LOG(LogTemp, Warning, TEXT("Left"))
		}
		
		

		//For WallRuns That Can Change Z Height
		//if you are holding in the direction you are wall running, no gravity is applied, if you are holding in no direction or away, the ngravity starts to build

		float TangentAccel = Acceleration.GetSafeNormal() | Velocity.GetSafeNormal2D();
		bool bVelUp = Velocity.Z > 0.f;
		//Velocity.Z += GetGravityZ() * WallRunGravityScaleCurve->GetFloatValue(bVelUp ? 0.f : TangentAccel) * timeTick;

		//If min or max speeds are exceeded end wall run
		if (SpeedCheck()) {
			SetMovementMode(MOVE_Falling);
			StartNewPhysics(RemainingTime, Iterations);
			return;
		}

		//ComputeMoveParameters
		const FVector Delta = timeTick * Velocity;
		const bool bZeroDelta = Delta.IsNearlyZero();
		if (bZeroDelta) {
			RemainingTime = 0.f;
		}
		else
		{
			FHitResult WallAttractionHit;
			FHitResult WallRunHit;
			SafeMoveUpdatedComponent(Delta, UpdatedComponent->GetComponentQuat(), true, WallRunHit);
			DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + Delta * 50, FColor::Blue, false, 1 / 60, 10, 1.25);
			FVector WallAttractionDelta = -WallHit.Normal * WallAttractionForce * timeTick;
			SafeMoveUpdatedComponent(WallAttractionDelta, UpdatedComponent->GetComponentQuat(), true, WallAttractionHit);

			if (WallRunHit.IsValidBlockingHit()) {
				HandleImpact(WallRunHit, timeTick, Delta);
				SlideAlongSurface(Delta, 1.f-WallRunHit.Time, WallRunHit.Normal, WallRunHit, true);
			}
		}

		//implement slide along


		if (UpdatedComponent->GetComponentLocation() == OldLocation) {
			UE_LOG(LogTemp, Warning, TEXT("No Movement Break"))
			Velocity = FVector(0,0,0);
			RemainingTime = 0.f;
			break;
		}

		//make velocity match the actual movement that is created by using velocity and adding wall attraction force
		Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / timeTick;

		//DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + Velocity * 100, FColor::Green, false, 1 / 60, 10, 1.25);
		if (Velocity.Size() == 0)UE_LOG(LogTemp, Warning, TEXT("Zero velocity"));
	}

	//make sure all wall run requirements are still met
#pragma region LineTraceParamCheck

	

	FVector Start = UpdatedComponent->GetComponentLocation();
	FVector CastDelta = Velocity.GetSafeNormal().RotateAngleAxis(90, FVector::UpVector) * CapR() * 2;
	FVector End = safe_bWallRunRight ? Start + CastDelta : Start - CastDelta;
	DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), safe_bWallRunRight ? UpdatedComponent->GetComponentLocation() + CastDelta * 5: UpdatedComponent->GetComponentLocation() - CastDelta * 5, FColor::Red, false, 1 / 60, 10, 1.5);
	auto Params = CustomCharacterOwner->GetIgnoreCharacterParams();
	FHitResult FloorHit, WallHit2;
	GetWorld()->LineTraceSingleByProfile(WallHit2, Start, End, "BlockAll", Params);
	if (!WallHit2.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Warning, TEXT("wall hit error"))
		SetMovementMode(MOVE_Falling);
	}

	

#pragma endregion

#pragma region SweepParamCheck

	/*

	FHitResult WallHit;
	FCollisionShape StructureCollision;
	FVector Start = UpdatedComponent->GetComponentLocation();
	StructureCollision = CustomCharacterOwner->GetWallRunScanMesh();
	FVector CastDelta = Velocity.GetSafeNormal2D().RotateAngleAxis(90, FVector::UpVector) * WallRunScanDistance * 1.5;
	if (safe_bWallRunRight) {
		GetWorld()->SweepSingleByProfile(WallHit, Start, Start + CastDelta, UpdatedComponent->GetComponentQuat(), "BlockAll", StructureCollision, CustomCharacterOwner->GetIgnoreCharacterParams());
	}
	else {
		GetWorld()->SweepSingleByProfile(WallHit, Start, Start - CastDelta, UpdatedComponent->GetComponentQuat(), "BlockAll", StructureCollision, CustomCharacterOwner->GetIgnoreCharacterParams());
	}

	*/

#pragma endregion


}

void UCustomMoveComponent::PhysRailGrind(float deltaTime, int32 Iterations)
{
	if (deltaTime < MIN_TICK_TIME) {
		return;
	}
	if (!CharacterOwner || (!CharacterOwner->Controller && !bRunPhysicsWithNoController && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && (CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy)))
	{
		Acceleration = FVector::ZeroVector;
		Velocity = FVector::ZeroVector;
		return;
	}

	bJustTeleported = false;
	float RemainingTime = deltaTime;

	while (RemainingTime >= MIN_TICK_TIME && (Iterations < MaxSimulationIterations) && CharacterOwner && (CharacterOwner->Controller || bRunPhysicsWithNoController || (CharacterOwner->GetLocalRole() == ROLE_SimulatedProxy))) {

		Iterations++;
		bJustTeleported = false;
		const float timeTick = GetSimulationTimeStep(RemainingTime, Iterations);
		RemainingTime -= timeTick;


		//Preform movement
		ARailGrindRails* SelectedRail = nullptr;
		USplineComponent* SelectedSpline = nullptr;
		float SelectedRailDistFrom;
		float SelectedRailDistAlong;
		FVector SelectedRailLocation;
		float SplineEndDistance;
		FVector FootLocation = UpdatedComponent->GetComponentLocation() - FVector(0, 0, CapHH());
		FHitResult RailGrindHit;
		TArray<AActor*> DetectedGrindRails = CustomCharacterOwner->GetRailGrindHitBoxOverlapped();

		if (DetectedGrindRails.Num() <= 0) {
			SetMovementMode(MOVE_Falling);
			StartNewPhysics(RemainingTime, Iterations);
			break;
		}

		for (size_t i = 0; i < DetectedGrindRails.Num() - 1; i++){
			ARailGrindRails* CurrentRail = Cast<ARailGrindRails>(DetectedGrindRails[i]);
			FVector ClosestOnSplineWorld = CurrentRail->GetGrindSplineClosestLocation(FootLocation);
			float CurrentRailDist = FMath::Abs((ClosestOnSplineWorld - FootLocation).Size());
			if (SelectedRail == nullptr || SelectedRailDistFrom > CurrentRailDist) {
				SelectedRail = CurrentRail;
				SelectedRailLocation = SelectedRail->GetGrindSplineClosestLocation(FootLocation);
				SelectedRailDistFrom = CurrentRailDist;
				SelectedSpline = SelectedRail->GrindRail;
				SelectedRailDistAlong = SelectedSpline->GetDistanceAlongSplineAtLocation(SelectedRailLocation, ESplineCoordinateSpace::World);
				SplineEndDistance = SelectedSpline->GetDistanceAlongSplineAtSplinePoint((SelectedSpline->GetNumberOfSplinePoints()) - 1);
			}
		}
		//Determine Direction To move for when you are moving and when you have no XY plane velocity
		FVector ForwardToBeUsed = FVector::ZeroVector;
		if (Velocity.GetSafeNormal2D() == FVector::ZeroVector) {
			ForwardToBeUsed = CustomCharacterOwner->GetCameraDirection();
		}
		else {
			ForwardToBeUsed = Velocity.GetSafeNormal2D();
		}
		FVector SplineForward = SelectedSpline->GetDirectionAtDistanceAlongSpline(SelectedRailDistAlong, ESplineCoordinateSpace::World);
		int DirectionModifier;

		if ((FMath::Acos(FVector::DotProduct(ForwardToBeUsed, SplineForward))) > (PI / 2)) {
			DirectionModifier = -1;
		}
		else {
			DirectionModifier = 1;
		}
		//Check if closest point is the end of the rail i.e you will immediately fall off and if so abort
		if (DirectionModifier == 1 && (SelectedRailDistAlong == SplineEndDistance) || DirectionModifier == -1 && (SelectedRailDistAlong == 0.f)) {
			SetMovementMode(MOVE_Falling);
			StartNewPhysics(RemainingTime, Iterations);
			return;
		}
		 
		//Preform movemnt to rail if not on rail and are moving fast enough to cover the distance, else abort
		if (Velocity.Size() > SelectedRailDistFrom) {
			SafeMoveUpdatedComponent(((FootLocation - SelectedRailLocation) - FootLocation), UpdatedComponent->GetComponentQuat(), true, RailGrindHit);
		}
		else {
			SetMovementMode(MOVE_Falling);
			StartNewPhysics(RemainingTime, Iterations);
			return;
		}
		//DetermineNextLocationInWorldSpaceOfNextDistanceAlongSpline
		FootLocation = UpdatedComponent->GetComponentLocation() - FVector(0, 0, CapHH());
		float NextDistanceAlongRail = SelectedSpline->GetDistanceAlongSplineAtLocation(FootLocation, ESplineCoordinateSpace::World) + (Velocity.Size() * timeTick * DirectionModifier);
		
		if (DirectionModifier == 1 && NextDistanceAlongRail > SplineEndDistance) {
			//if true, move to end of rail, fall off and start new physics making sure not to subtract the full timeTick since we have moved for less distance than we have velocity
			NextDistanceAlongRail = SplineEndDistance;
		}
		if (DirectionModifier == -1 && NextDistanceAlongRail < 0) {
			//if true, move to start of rail, fall off and start new physics making sure not to subtract the full timeTick since we have moved for less distance than we have velocity
			NextDistanceAlongRail = 0;
		}
		FVector NextIterationLocation(SelectedSpline->GetLocationAtDistanceAlongSpline(NextDistanceAlongRail, ESplineCoordinateSpace::World));
		FVector NextIterationDelta = FootLocation - NextIterationLocation;

		SafeMoveUpdatedComponent(NextIterationDelta, UpdatedComponent->GetComponentQuat(), true, RailGrindHit);

	}
}

void UCustomMoveComponent::PhysWalking(float deltaTime, int32 Iterations)
{
	if (deltaTime < MIN_TICK_TIME)
	{
		return;
	}

	if (!CharacterOwner || (!CharacterOwner->Controller && !bRunPhysicsWithNoController && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && (CharacterOwner->GetLocalRole() != ROLE_SimulatedProxy)))
	{
		Acceleration = FVector::ZeroVector;
		Velocity = FVector::ZeroVector;
		return;
	}

	if (!UpdatedComponent->IsQueryCollisionEnabled())
	{
		SetMovementMode(MOVE_Walking);
		return;
	}

	bJustTeleported = false;
	bool bCheckedFall = false;
	bool bTriedLedgeMove = false;
	float remainingTime = deltaTime;

	// Perform the move
	while ((remainingTime >= MIN_TICK_TIME) && (Iterations < MaxSimulationIterations) && CharacterOwner && (CharacterOwner->Controller || bRunPhysicsWithNoController || HasAnimRootMotion() || CurrentRootMotion.HasOverrideVelocity() || (CharacterOwner->GetLocalRole() == ROLE_SimulatedProxy)))
	{

		Iterations++;
		bJustTeleported = false;
		const float timeTick = GetSimulationTimeStep(remainingTime, Iterations);
		remainingTime -= timeTick;

		// Save current values
		UPrimitiveComponent* const OldBase = GetMovementBase();
		const FVector PreviousBaseLocation = (OldBase != NULL) ? OldBase->GetComponentLocation() : FVector::ZeroVector;
		const FVector OldLocation = UpdatedComponent->GetComponentLocation();
		const FFindFloorResult OldFloor = CurrentFloor;

		RestorePreAdditiveRootMotionVelocity();

		// Ensure velocity is horizontal.
		MaintainHorizontalGroundVelocity();
		const FVector OldVelocity = Velocity;
		Acceleration = FVector::VectorPlaneProject(Acceleration, -FVector(0.f, 0.f, -1.f));
		float RateOfAcceleration = 10 * timeTick;

		// Apply acceleration
		if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
		{

			if (Acceleration != FVector(0, 0, 0) && Velocity == FVector(0,0,0)) {
				//make this happen over time rather than instantly
				Velocity += Acceleration.GetSafeNormal() * RateOfAcceleration;

				//UE_LOG(LogTemp, Warning, TEXT("StartFromStop"))
			}

			if (Velocity.Size() < MaxCustomMovementSpeed && Velocity != FVector(0,0,0)) {
				//make this happen over time rather than instantly
				Velocity *= ((MaxCustomMovementSpeed / Velocity.Size())   );

				//UE_LOG(LogTemp, Warning, TEXT("SpeedCorrected"))
			}
			
			
			if (Velocity.GetSafeNormal2D() != Acceleration.GetSafeNormal2D()) {

					DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + Velocity.GetSafeNormal2D() * 150, FColor::Blue, false, 1 / 60, 1.5);
					DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + Acceleration.GetSafeNormal2D() * 100, FColor::Red, false, 1 / 60, 2);


				//Shoot out left and right Vectors
				FVector LeftDirection = (FVector(Velocity.X, Velocity.Y, 0.f)).RotateAngleAxis(270, FVector::UpVector);
				FVector RightDirection = (FVector(Velocity.X, Velocity.Y, 0.f)).RotateAngleAxis(90, FVector::UpVector);

				float DotProduct = FVector::DotProduct(Acceleration.GetSafeNormal(), Velocity.GetSafeNormal());
				float RadianDelta = FMath::Acos(DotProduct);
				float DegreeDelta = FMath::RadiansToDegrees(RadianDelta);
				float Turnrate = 100.f;
				
				float LeftDotProduct = FVector::DotProduct(Acceleration.GetSafeNormal(), LeftDirection.GetSafeNormal());
				float LeftRadianDelta = FMath::Acos(LeftDotProduct);

				float RightDotProduct = FVector::DotProduct(Acceleration.GetSafeNormal(), RightDirection.GetSafeNormal());
				float RightRadianDelta = FMath::Acos(RightDotProduct);


				if (DegreeDelta != 0 && Acceleration != FVector(0, 0, 0)) {

					//UE_LOG(LogTemp, Warning, TEXT("CorrectionMade"))
					if (DegreeDelta > Turnrate * timeTick) {
						if (RightRadianDelta > LeftRadianDelta || RightRadianDelta == LeftRadianDelta) {
							Velocity = Velocity.RotateAngleAxis(Turnrate * timeTick, FVector::DownVector);
						}
						if (RightRadianDelta < LeftRadianDelta) {
							Velocity = Velocity.RotateAngleAxis(-Turnrate * timeTick, FVector::DownVector);
						}	
					}
					else{

						//UE_LOG(LogTemp, Warning, TEXT("Small Correct"))
						if (RightRadianDelta > LeftRadianDelta || RightRadianDelta == LeftRadianDelta) {
							Velocity = Velocity.RotateAngleAxis(DegreeDelta, FVector::DownVector);
						}
						if (RightRadianDelta < LeftRadianDelta) {
							Velocity = Velocity.RotateAngleAxis(-DegreeDelta, FVector::DownVector);
						}
					}
				}
				//else { UE_LOG(LogTemp, Warning, TEXT("No Correctionmade")) }
			}
		}

		ApplyRootMotionToVelocity(timeTick);

		FVector LeftDirection = (FVector(Velocity.X, Velocity.Y, 0.f)).RotateAngleAxis(270, FVector::UpVector);
		FVector RightDirection = (FVector(Velocity.X, Velocity.Y, 0.f)).RotateAngleAxis(90, FVector::UpVector);

		DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + Velocity, FColor::Green, false, 1 / 60);
		DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + LeftDirection, FColor::Green, false, 1 / 60);
		DrawDebugLine(GetWorld(), UpdatedComponent->GetComponentLocation(), UpdatedComponent->GetComponentLocation() + RightDirection, FColor::Green, false, 1 / 60);

		if (IsFalling())
		{
			// Root motion could have put us into Falling.
			// No movement has taken place this movement tick so we pass on full time/past iteration count
			StartNewPhysics(remainingTime + timeTick, Iterations - 1);
			return;
		}

		// Compute move parameters
		const FVector MoveVelocity = Velocity;
		const FVector Delta = timeTick * MoveVelocity;
		const bool bZeroDelta = Delta.IsNearlyZero();
		FStepDownResult StepDownResult;

		if (bZeroDelta)
		{
			remainingTime = 0.f;
		}
		else
		{
			// try to move forward
			MoveAlongFloor(MoveVelocity, timeTick, &StepDownResult);

			if (IsFalling())
			{
				// pawn decided to jump up
				const float DesiredDist = Delta.Size();
				if (DesiredDist > UE_KINDA_SMALL_NUMBER)
				{
					const float ActualDist = (UpdatedComponent->GetComponentLocation() - OldLocation).Size2D();
					remainingTime += timeTick * (1.f - FMath::Min(1.f, ActualDist / DesiredDist));
				}
				StartNewPhysics(remainingTime, Iterations);
				return;
			}
			else if (IsSwimming()) //just entered water
			{
				StartSwimming(OldLocation, OldVelocity, timeTick, remainingTime, Iterations);
				return;
			}
		}

		// Update floor.
		// StepUp might have already done it for us.
		if (StepDownResult.bComputedFloor)
		{
			CurrentFloor = StepDownResult.FloorResult;
		}
		else
		{
			FindFloor(UpdatedComponent->GetComponentLocation(), CurrentFloor, bZeroDelta, NULL);
		}

		// check for ledges here
		const bool bCheckLedges = !CanWalkOffLedges();
		if (bCheckLedges && !CurrentFloor.IsWalkableFloor())
		{
			// calculate possible alternate movement
			const FVector GravDir = FVector(0.f, 0.f, -1.f);
			const FVector NewDelta = bTriedLedgeMove ? FVector::ZeroVector : GetLedgeMove(OldLocation, Delta, GravDir);
			if (!NewDelta.IsZero())
			{
				// first revert this move
				RevertMove(OldLocation, OldBase, PreviousBaseLocation, OldFloor, false);

				// avoid repeated ledge moves if the first one fails
				bTriedLedgeMove = true;

				// Try new movement direction
				Velocity = NewDelta / timeTick;
				remainingTime += timeTick;
				continue;
			}
			else
			{
				// see if it is OK to jump
				// @todo collision : only thing that can be problem is that oldbase has world collision on
				bool bMustJump = bZeroDelta || (OldBase == NULL || (!OldBase->IsQueryCollisionEnabled() && MovementBaseUtility::IsDynamicBase(OldBase)));
				if ((bMustJump || !bCheckedFall) && CheckFall(OldFloor, CurrentFloor.HitResult, Delta, OldLocation, remainingTime, timeTick, Iterations, bMustJump))
				{
					return;
				}
				bCheckedFall = true;

				// revert this move
				RevertMove(OldLocation, OldBase, PreviousBaseLocation, OldFloor, true);
				remainingTime = 0.f;
				break;
			}
		}
		else
		{
			// Validate the floor check
			if (CurrentFloor.IsWalkableFloor())
			{
				if (ShouldCatchAir(OldFloor, CurrentFloor))
				{
					HandleWalkingOffLedge(OldFloor.HitResult.ImpactNormal, OldFloor.HitResult.Normal, OldLocation, timeTick);
					if (IsMovingOnGround())
					{
						// If still walking, then fall. If not, assume the user set a different mode they want to keep.
						StartFalling(Iterations, remainingTime, timeTick, Delta, OldLocation);
					}
					return;
				}

				AdjustFloorHeight();
				SetBase(CurrentFloor.HitResult.Component.Get(), CurrentFloor.HitResult.BoneName);
			}
			else if (CurrentFloor.HitResult.bStartPenetrating && remainingTime <= 0.f)
			{
				// The floor check failed because it started in penetration
				// We do not want to try to move downward because the downward sweep failed, rather we'd like to try to pop out of the floor.
				FHitResult Hit(CurrentFloor.HitResult);
				Hit.TraceEnd = Hit.TraceStart + RotateGravityToWorld(FVector(0.f, 0.f, MAX_FLOOR_DIST));
				const FVector RequestedAdjustment = GetPenetrationAdjustment(Hit);
				ResolvePenetration(RequestedAdjustment, Hit, UpdatedComponent->GetComponentQuat());
				bForceNextFloorCheck = true;
			}

			// check if just entered water
			if (IsSwimming())
			{
				StartSwimming(OldLocation, Velocity, timeTick, remainingTime, Iterations);
				return;
			}

			// See if we need to start falling.
			if (!CurrentFloor.IsWalkableFloor() && !CurrentFloor.HitResult.bStartPenetrating)
			{
				const bool bMustJump = bJustTeleported || bZeroDelta || (OldBase == NULL || (!OldBase->IsQueryCollisionEnabled() && MovementBaseUtility::IsDynamicBase(OldBase)));
				if ((bMustJump || !bCheckedFall) && CheckFall(OldFloor, CurrentFloor.HitResult, Delta, OldLocation, remainingTime, timeTick, Iterations, bMustJump))
				{
					return;
				}
				bCheckedFall = true;
			}
		}


		// Allow overlap events and such to change physics state and velocity
		if (IsMovingOnGround())
		{
			// Make velocity reflect actual move
			if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity() && timeTick >= MIN_TICK_TIME)
			{
				// TODO-RootMotionSource: Allow this to happen during partial override Velocity, but only set allowed axes?
				Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / timeTick;
				MaintainHorizontalGroundVelocity();
			}
		}

		// If we didn't move at all this iteration then abort (since future iterations will also be stuck).
		if (UpdatedComponent->GetComponentLocation() == OldLocation)
		{
			remainingTime = 0.f;
			break;
		}
	}

	if (IsMovingOnGround())
	{
		MaintainHorizontalGroundVelocity();
	}
}

void UCustomMoveComponent::PhysFalling(float deltaTime, int32 Iterations)
{
	if (deltaTime < MIN_TICK_TIME)
	{
		return;
	}

	FVector FallAcceleration = GetFallingLateralAcceleration(deltaTime);
	const FVector GravityRelativeFallAcceleration = RotateWorldToGravity(FallAcceleration);
	FallAcceleration = RotateGravityToWorld(FVector(GravityRelativeFallAcceleration.X, GravityRelativeFallAcceleration.Y, 0));
	const bool bHasLimitedAirControl = ShouldLimitAirControl(deltaTime, FallAcceleration);

	float remainingTime = deltaTime;
	while ((remainingTime >= MIN_TICK_TIME) && (Iterations < MaxSimulationIterations))
	{
		Iterations++;
		float timeTick = GetSimulationTimeStep(remainingTime, Iterations);
		remainingTime -= timeTick;

		const FVector OldLocation = UpdatedComponent->GetComponentLocation();
		const FQuat PawnRotation = UpdatedComponent->GetComponentQuat();
		bJustTeleported = false;

		const FVector OldVelocityWithRootMotion = Velocity;

		RestorePreAdditiveRootMotionVelocity();

		const FVector OldVelocity = Velocity;

		// Apply input
		const float MaxDecel = GetMaxBrakingDeceleration();
		if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
		{
			// Compute Velocity
			{
				// Acceleration = FallAcceleration for CalcVelocity(), but we restore it after using it.
				TGuardValue<FVector> RestoreAcceleration(Acceleration, FallAcceleration);
				if (HasCustomGravity())
				{
					Velocity = FVector::VectorPlaneProject(Velocity, RotateGravityToWorld(FVector::UpVector));
					const FVector GravityRelativeOffset = OldVelocity - Velocity;
					CalcVelocity(timeTick, FallingLateralFriction, false, MaxDecel);
					Velocity += GravityRelativeOffset;
				}
				else
				{
					Velocity.Z = 0.f;
					//CalcVelocity(timeTick, FallingLateralFriction, false, MaxDecel);

					//custom start
					

					if (Velocity.GetSafeNormal() != Acceleration.GetSafeNormal()) {

						

						//Shoot out left and right Vectors
						FVector LeftDirection = (FVector(Velocity.X, Velocity.Y, 0.f)).RotateAngleAxis(270, FVector::UpVector);
						FVector RightDirection = (FVector(Velocity.X, Velocity.Y, 0.f)).RotateAngleAxis(90, FVector::UpVector);

						float DotProduct = FVector::DotProduct(Acceleration.GetSafeNormal(), Velocity.GetSafeNormal());
						float RadianDelta = FMath::Acos(DotProduct);
						float DegreeDelta = FMath::RadiansToDegrees(RadianDelta);
						float Turnrate = 100.f;

						float LeftDotProduct = FVector::DotProduct(Acceleration.GetSafeNormal(), LeftDirection.GetSafeNormal());
						float LeftRadianDelta = FMath::Acos(LeftDotProduct);

						float RightDotProduct = FVector::DotProduct(Acceleration.GetSafeNormal(), RightDirection.GetSafeNormal());
						float RightRadianDelta = FMath::Acos(RightDotProduct);


						if (DegreeDelta != 0 && Acceleration != FVector(0, 0, 0)) {
							if (DegreeDelta > Turnrate * timeTick) {
								if (RightRadianDelta > LeftRadianDelta || RightRadianDelta == LeftRadianDelta) {
									Velocity = Velocity.RotateAngleAxis(Turnrate * timeTick, FVector::DownVector);
								}
								if (RightRadianDelta < LeftRadianDelta) {
									Velocity = Velocity.RotateAngleAxis(-Turnrate * timeTick, FVector::DownVector);
								}
							}
							else {
								if (RightRadianDelta > LeftRadianDelta || RightRadianDelta == LeftRadianDelta) {
									Velocity = Velocity.RotateAngleAxis(DegreeDelta, FVector::DownVector);
								}
								if (RightRadianDelta < LeftRadianDelta) {
									Velocity = Velocity.RotateAngleAxis(-DegreeDelta, FVector::DownVector);
								}
							}
						}
					}
					//custom end

					Velocity.Z = OldVelocity.Z;
				}
			}
		}

		// Compute current gravity
		const FVector Gravity = -GetGravityDirection() * GetGravityZ();
		float GravityTime = timeTick;

		// If jump is providing force, gravity may be affected.
		bool bEndingJumpForce = false;
		if (CharacterOwner->JumpForceTimeRemaining > 0.0f)
		{
			// Consume some of the force time. Only the remaining time (if any) is affected by gravity when bApplyGravityWhileJumping=false.
			const float JumpForceTime = FMath::Min(CharacterOwner->JumpForceTimeRemaining, timeTick);
			GravityTime = bApplyGravityWhileJumping ? timeTick : FMath::Max(0.0f, timeTick - JumpForceTime);

			// Update Character state
			CharacterOwner->JumpForceTimeRemaining -= JumpForceTime;
			if (CharacterOwner->JumpForceTimeRemaining <= 0.0f)
			{
				CharacterOwner->ResetJumpState();
				bEndingJumpForce = true;
			}
		}

		// Apply gravity
		Velocity = NewFallVelocity(Velocity, Gravity, GravityTime);

		//UE_LOG(LogCharacterMovement, Log, TEXT("dt=(%.6f) OldLocation=(%s) OldVelocity=(%s) OldVelocityWithRootMotion=(%s) NewVelocity=(%s)"), timeTick, *(UpdatedComponent->GetComponentLocation()).ToString(), *OldVelocity.ToString(), *OldVelocityWithRootMotion.ToString(), *Velocity.ToString());
		ApplyRootMotionToVelocity(timeTick);
		DecayFormerBaseVelocity(timeTick);

		// See if we need to sub-step to exactly reach the apex. This is important for avoiding "cutting off the top" of the trajectory as framerate varies.
		const FVector GravityRelativeOldVelocityWithRootMotion = RotateWorldToGravity(OldVelocityWithRootMotion);
		if (CharacterMovementCVars::ForceJumpPeakSubstep && GravityRelativeOldVelocityWithRootMotion.Z > 0.f && RotateWorldToGravity(Velocity).Z <= 0.f && NumJumpApexAttempts < MaxJumpApexAttemptsPerSimulation)
		{
			const FVector DerivedAccel = (Velocity - OldVelocityWithRootMotion) / timeTick;
			const FVector GravityRelativeDerivedAccel = RotateWorldToGravity(DerivedAccel);
			if (!FMath::IsNearlyZero(GravityRelativeDerivedAccel.Z))
			{
				const float TimeToApex = -GravityRelativeOldVelocityWithRootMotion.Z / GravityRelativeDerivedAccel.Z;

				// The time-to-apex calculation should be precise, and we want to avoid adding a substep when we are basically already at the apex from the previous iteration's work.
				const float ApexTimeMinimum = 0.0001f;
				if (TimeToApex >= ApexTimeMinimum && TimeToApex < timeTick)
				{
					const FVector ApexVelocity = OldVelocityWithRootMotion + (DerivedAccel * TimeToApex);
					if (HasCustomGravity())
					{
						const FVector GravityRelativeApexVelocity = RotateWorldToGravity(ApexVelocity);
						Velocity = RotateGravityToWorld(FVector(GravityRelativeApexVelocity.X, GravityRelativeApexVelocity.Y, 0)); // Should be nearly zero anyway, but this makes apex notifications consistent.
					}
					else
					{
						Velocity = ApexVelocity;
						Velocity.Z = 0.f; // Should be nearly zero anyway, but this makes apex notifications consistent.
					}

					// We only want to move the amount of time it takes to reach the apex, and refund the unused time for next iteration.
					const float TimeToRefund = (timeTick - TimeToApex);

					remainingTime += TimeToRefund;
					timeTick = TimeToApex;
					Iterations--;
					NumJumpApexAttempts++;

					// Refund time to any active Root Motion Sources as well
					for (TSharedPtr<FRootMotionSource> RootMotionSource : CurrentRootMotion.RootMotionSources)
					{
						const float RewoundRMSTime = FMath::Max(0.0f, RootMotionSource->GetTime() - TimeToRefund);
						RootMotionSource->SetTime(RewoundRMSTime);
					}
				}
			}
		}

		if (bNotifyApex && (RotateWorldToGravity(Velocity).Z < 0.f))
		{
			// Just passed jump apex since now going down
			bNotifyApex = false;
			NotifyJumpApex();
		}

		// Compute change in position (using midpoint integration method).
		FVector Adjusted = 0.5f * (OldVelocityWithRootMotion + Velocity) * timeTick;

		// Special handling if ending the jump force where we didn't apply gravity during the jump.
		if (bEndingJumpForce && !bApplyGravityWhileJumping)
		{
			// We had a portion of the time at constant speed then a portion with acceleration due to gravity.
			// Account for that here with a more correct change in position.
			const float NonGravityTime = FMath::Max(0.f, timeTick - GravityTime);
			Adjusted = (OldVelocityWithRootMotion * NonGravityTime) + (0.5f * (OldVelocityWithRootMotion + Velocity) * GravityTime);
		}

		// Move
		FHitResult Hit(1.f);
		SafeMoveUpdatedComponent(Adjusted, PawnRotation, true, Hit);

		if (!HasValidData())
		{
			return;
		}

		float LastMoveTimeSlice = timeTick;
		float subTimeTickRemaining = timeTick * (1.f - Hit.Time);

		if (IsSwimming()) //just entered water
		{
			remainingTime += subTimeTickRemaining;
			StartSwimming(OldLocation, OldVelocity, timeTick, remainingTime, Iterations);
			return;
		}
		else if (Hit.bBlockingHit)
		{
			if (IsValidLandingSpot(UpdatedComponent->GetComponentLocation(), Hit))
			{
				remainingTime += subTimeTickRemaining;
				ProcessLanded(Hit, remainingTime, Iterations);
				return;
			}
			else
			{
				// Compute impact deflection based on final velocity, not integration step.
				// This allows us to compute a new velocity from the deflected vector, and ensures the full gravity effect is included in the slide result.
				Adjusted = Velocity * timeTick;

				// See if we can convert a normally invalid landing spot (based on the hit result) to a usable one.
				if (!Hit.bStartPenetrating && ShouldCheckForValidLandingSpot(timeTick, Adjusted, Hit))
				{
					const FVector PawnLocation = UpdatedComponent->GetComponentLocation();
					FFindFloorResult FloorResult;
					FindFloor(PawnLocation, FloorResult, false);
					if (FloorResult.IsWalkableFloor() && IsValidLandingSpot(PawnLocation, FloorResult.HitResult))
					{
						remainingTime += subTimeTickRemaining;
						ProcessLanded(FloorResult.HitResult, remainingTime, Iterations);
						return;
					}
				}

				HandleImpact(Hit, LastMoveTimeSlice, Adjusted);

				// If we've changed physics mode, abort.
				if (!HasValidData() || !IsFalling())
				{
					return;
				}

				// Limit air control based on what we hit.
				// We moved to the impact point using air control, but may want to deflect from there based on a limited air control acceleration.
				FVector VelocityNoAirControl = OldVelocity;
				FVector AirControlAccel = Acceleration;
				if (bHasLimitedAirControl)
				{
					// Compute VelocityNoAirControl
					{
						// Find velocity *without* acceleration.
						TGuardValue<FVector> RestoreAcceleration(Acceleration, FVector::ZeroVector);
						TGuardValue<FVector> RestoreVelocity(Velocity, OldVelocity);
						if (HasCustomGravity())
						{
							Velocity = FVector::VectorPlaneProject(Velocity, RotateGravityToWorld(FVector::UpVector));
							const FVector GravityRelativeOffset = OldVelocity - Velocity;
							CalcVelocity(timeTick, FallingLateralFriction, false, MaxDecel);
							VelocityNoAirControl = Velocity + GravityRelativeOffset;
						}
						else
						{
							Velocity.Z = 0.f;
							CalcVelocity(timeTick, FallingLateralFriction, false, MaxDecel);
							VelocityNoAirControl = FVector(Velocity.X, Velocity.Y, OldVelocity.Z);
						}

						VelocityNoAirControl = NewFallVelocity(VelocityNoAirControl, Gravity, GravityTime);
					}

					const bool bCheckLandingSpot = false; // we already checked above.
					AirControlAccel = (Velocity - VelocityNoAirControl) / timeTick;
					const FVector AirControlDeltaV = LimitAirControl(LastMoveTimeSlice, AirControlAccel, Hit, bCheckLandingSpot) * LastMoveTimeSlice;
					Adjusted = (VelocityNoAirControl + AirControlDeltaV) * LastMoveTimeSlice;
				}

				const FVector OldHitNormal = Hit.Normal;
				const FVector OldHitImpactNormal = Hit.ImpactNormal;
				FVector Delta = ComputeSlideVector(Adjusted, 1.f - Hit.Time, OldHitNormal, Hit);

				// Compute velocity after deflection (only gravity component for RootMotion)
				const UPrimitiveComponent* HitComponent = Hit.GetComponent();
				if (CharacterMovementCVars::UseTargetVelocityOnImpact && !Velocity.IsNearlyZero() && MovementBaseUtility::IsSimulatedBase(HitComponent))
				{
					const FVector ContactVelocity = MovementBaseUtility::GetMovementBaseVelocity(HitComponent, NAME_None) + MovementBaseUtility::GetMovementBaseTangentialVelocity(HitComponent, NAME_None, Hit.ImpactPoint);
					const FVector NewVelocity = Velocity - Hit.ImpactNormal * FVector::DotProduct(Velocity - ContactVelocity, Hit.ImpactNormal);
					Velocity = HasAnimRootMotion() || CurrentRootMotion.HasOverrideVelocityWithIgnoreZAccumulate() ? FVector(Velocity.X, Velocity.Y, NewVelocity.Z) : NewVelocity;
				}
				else if (subTimeTickRemaining > UE_KINDA_SMALL_NUMBER && !bJustTeleported)
				{
					const FVector NewVelocity = (Delta / subTimeTickRemaining);
					Velocity = HasAnimRootMotion() || CurrentRootMotion.HasOverrideVelocityWithIgnoreZAccumulate() ? FVector(Velocity.X, Velocity.Y, NewVelocity.Z) : NewVelocity;
				}
				
				if (subTimeTickRemaining > UE_KINDA_SMALL_NUMBER && (Delta | Adjusted) > 0.f)
				{
					// Move in deflected direction.
					SafeMoveUpdatedComponent(Delta, PawnRotation, true, Hit);

					if (Hit.bBlockingHit)
					{
						// hit second wall
						LastMoveTimeSlice = subTimeTickRemaining;
						subTimeTickRemaining = subTimeTickRemaining * (1.f - Hit.Time);

						if (IsValidLandingSpot(UpdatedComponent->GetComponentLocation(), Hit))
						{
							remainingTime += subTimeTickRemaining;
							ProcessLanded(Hit, remainingTime, Iterations);
							return;
						}

						HandleImpact(Hit, LastMoveTimeSlice, Delta);

						// If we've changed physics mode, abort.
						if (!HasValidData() || !IsFalling())
						{
							return;
						}

						// Act as if there was no air control on the last move when computing new deflection.
						if (bHasLimitedAirControl && RotateWorldToGravity(Hit.Normal).Z > CharacterMovementConstants::VERTICAL_SLOPE_NORMAL_Z)
						{
							const FVector LastMoveNoAirControl = VelocityNoAirControl * LastMoveTimeSlice;
							Delta = ComputeSlideVector(LastMoveNoAirControl, 1.f, OldHitNormal, Hit);
						}

						FVector PreTwoWallDelta = Delta;
						TwoWallAdjust(Delta, Hit, OldHitNormal);

						// Limit air control, but allow a slide along the second wall.
						if (bHasLimitedAirControl)
						{
							const bool bCheckLandingSpot = false; // we already checked above.
							const FVector AirControlDeltaV = LimitAirControl(subTimeTickRemaining, AirControlAccel, Hit, bCheckLandingSpot) * subTimeTickRemaining;

							// Only allow if not back in to first wall
							if (FVector::DotProduct(AirControlDeltaV, OldHitNormal) > 0.f)
							{
								Delta += (AirControlDeltaV * subTimeTickRemaining);
							}
						}

						// Compute velocity after deflection (only gravity component for RootMotion)
						if (subTimeTickRemaining > UE_KINDA_SMALL_NUMBER && !bJustTeleported)
						{
							const FVector NewVelocity = (Delta / subTimeTickRemaining);
							Velocity = HasAnimRootMotion() || CurrentRootMotion.HasOverrideVelocityWithIgnoreZAccumulate() ? FVector(Velocity.X, Velocity.Y, NewVelocity.Z) : NewVelocity;
						}

						// bDitch=true means that pawn is straddling two slopes, neither of which it can stand on
						bool bDitch = ((RotateWorldToGravity(OldHitImpactNormal).Z > 0.f) && (RotateWorldToGravity(Hit.ImpactNormal).Z > 0.f) && (FMath::Abs(Delta.Z) <= UE_KINDA_SMALL_NUMBER) && ((Hit.ImpactNormal | OldHitImpactNormal) < 0.f));
						SafeMoveUpdatedComponent(Delta, PawnRotation, true, Hit);
						if (Hit.Time == 0.f)
						{
							// if we are stuck then try to side step
							FVector SideDelta = (OldHitNormal + Hit.ImpactNormal).GetSafeNormal2D();
							if (SideDelta.IsNearlyZero())
							{
								SideDelta = FVector(OldHitNormal.Y, -OldHitNormal.X, 0).GetSafeNormal();
							}
							SafeMoveUpdatedComponent(SideDelta, PawnRotation, true, Hit);
						}

						if (bDitch || IsValidLandingSpot(UpdatedComponent->GetComponentLocation(), Hit) || Hit.Time == 0.f)
						{
							remainingTime = 0.f;
							ProcessLanded(Hit, remainingTime, Iterations);
							return;
						}
						else if (GetPerchRadiusThreshold() > 0.f && Hit.Time == 1.f && RotateWorldToGravity(OldHitImpactNormal).Z >= GetWalkableFloorZ())
						{
							// We might be in a virtual 'ditch' within our perch radius. This is rare.
							const FVector PawnLocation = UpdatedComponent->GetComponentLocation();
							const float ZMovedDist = FMath::Abs(RotateWorldToGravity(PawnLocation - OldLocation).Z);
							const float MovedDist2DSq = FVector::VectorPlaneProject(PawnLocation - OldLocation, RotateGravityToWorld(FVector::UpVector)).Size2D();
							if (ZMovedDist <= 0.2f * timeTick && MovedDist2DSq <= 4.f * timeTick)
							{
								FVector GravityRelativeVelocity = RotateWorldToGravity(Velocity);
								GravityRelativeVelocity.X += 0.25f * GetMaxSpeed() * (RandomStream.FRand() - 0.5f);
								GravityRelativeVelocity.Y += 0.25f * GetMaxSpeed() * (RandomStream.FRand() - 0.5f);
								GravityRelativeVelocity.Z = FMath::Max<float>(JumpZVelocity * 0.25f, 1.f);
								Velocity = RotateGravityToWorld(GravityRelativeVelocity);
								Delta = Velocity * timeTick;
								SafeMoveUpdatedComponent(Delta, PawnRotation, true, Hit);
							}
						}
					}
				}
			}
		}

		FVector GravityRelativeVelocity = RotateWorldToGravity(Velocity);
		if (GravityRelativeVelocity.SizeSquared2D() <= UE_KINDA_SMALL_NUMBER * 10.f)
		{
			GravityRelativeVelocity.X = 0.f;
			GravityRelativeVelocity.Y = 0.f;
			Velocity = RotateGravityToWorld(GravityRelativeVelocity);
		}
	}
}
#pragma endregion


