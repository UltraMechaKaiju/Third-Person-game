// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RailGrindRails.h"

#include "CustomMoveComponent.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_None UMETA(Hidden),
	CMOVE_WallRun UMETA(DisplayName = "Skate"),
	CMOVE_RailGrind UMETA(DisplayName = "Grind"),
	CMOVE_Max UMETA(Hidden),
};


UCLASS()
class NEWCPPTUTORIAL_API UCustomMoveComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	class FSavedMove_Custom : public FSavedMove_Character
	{
		typedef FSavedMove_Character Super;

		//custom variables
		ARailGrindRails* Saved_GrindRail;
		float Saved_GrindRailDistAlong;

		//custom flags
		uint8 saved_bCanRailGrind : 1;
		uint8 Saved_bWallRunRight : 1;

		virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override;
		virtual void Clear() override;
		virtual uint8 GetCompressedFlags() const override;
		virtual void SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData) override;
		virtual void PrepMoveFor(ACharacter* C) override;

	};

	class FNetworkPredictionData_Client_Custom : public FNetworkPredictionData_Client_Character
	{
	public:
		FNetworkPredictionData_Client_Custom(const UCharacterMovementComponent& ClientMovement);

		typedef FNetworkPredictionData_Client_Character Super;

		virtual FSavedMovePtr AllocateNewMove() override;
	};

	UPROPERTY(EditDefaultsOnly) float Sprint_MaxSpeed = 1200;
	UPROPERTY(EditDefaultsOnly) float Walk_MaxSpeed = 600;

	//wallRun Params
	UPROPERTY(EditDefaultsOnly) float WallRunScanDistance = 25.f;

	UPROPERTY(EditDefaultsOnly) float MinWallRunSpeed = 200.f;
	UPROPERTY(EditDefaultsOnly) float MaxWallRunSpeed = 800.f;
	UPROPERTY(EditDefaultsOnly) float MaxVerticalRunSpeed = 200.f;
	UPROPERTY(EditDefaultsOnly) float WallRunPullAwayAngle = 75;
	UPROPERTY(EditDefaultsOnly) float MinWallRunHeight = 50.f;
	UPROPERTY(EditDefaultsOnly) float WallJumpOffForce = 200.f;
	UPROPERTY(EditDefaultsOnly) float WallAttractionForce = 1000.f;
	UPROPERTY(EditDefaultsOnly) UCurveFloat* WallRunGravityScaleCurve;
	UPROPERTY(EditDefaultsOnly) int WRMinLeaveAngle = 20;
	UPROPERTY(EditDefaultsOnly) int WRMaxLeaveAngle = 80;

	//RailGrindParams
	UPROPERTY(EditDefaultsOnly) float RGPullAwayAngleMax = 90;
	UPROPERTY(EditDefaultsOnly) float RGAcceptableRadiansFromVertical = FMath::DegreesToRadians(10);
	UPROPERTY(EditDefaultsOnly) float RGMaxLeaveRadians = FMath::DegreesToRadians(90);/*Max angle the player can modify their heading when jumping off a rail*/
	UPROPERTY(EditDefaultsOnly) float RGMaxLeaveRadiansLeaning = FMath::DegreesToRadians(45);/*Max angle the player can modify their heading when jumping off a rail WHILE LEANING TO ONE SIDE OR THE OTHER*/
	UPROPERTY(EditDefaultsOnly) float RGCorrectionAllowance = FMath::DegreesToRadians(45);
	UPROPERTY(EditDefaultsOnly) float RGSignificantLeanThreshold = FMath::DegreesToRadians(10);/*How far the player has to be leaning to one side or the other to be considered leaning*/
	UPROPERTY(EditDefaultsOnly) float RGMinSpeed = 100;

	//DEBUG ONLY

	float RGPrevDist;


	//client side Flags

	bool safe_bCanRailGrind;
	bool safe_bWallRunRight;

	//client suide variables
	ARailGrindRails* Safe_GrindRail;

	UStaticMeshComponent* RailGrindStaticMesh;
	
	float Safe_GrindRailDistAlong;
	

public:
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;

	UCustomMoveComponent();

	UFUNCTION(BlueprintCallable) void SprintPressed();
	UFUNCTION(BlueprintCallable) void SprintReleased();

	UPROPERTY(Transient) 
	class AXpCharacter* CustomCharacterOwner;

	UFUNCTION(BlueprintPure)
	bool IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const;

	virtual bool CanAttemptJump() const override;
	virtual bool DoJump(bool bReplayingMoves) override;
	virtual float GetMaxSpeed() const override;
	virtual float GetMaxBrakingDeceleration() const override;
	UFUNCTION(BlueprintPure) bool IsWallRunning() const { return IsCustomMovementMode(CMOVE_WallRun); }
	UFUNCTION(BlueprintPure) bool WallRunningIsRight() const { return safe_bWallRunRight; }
	UFUNCTION(BlueprintCallable) bool SpeedCheck();

	UFUNCTION(BlueprintPure) bool IsRailGrinding() const { return IsCustomMovementMode(CMOVE_RailGrind); }

	float CapR() const;
	float CapHH() const;

	float MinWallRunDetectRadius = 3;
	//float WallRunLineTraceLength = (2.f * WallRunDetectRadius) / (FMath::Sqrt(3.f));
	float WallRunLineTraceLength = 34;

protected:
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

	virtual void InitializeComponent() override;

	virtual void UpdateCharacterStateBeforeMovement(float DeltaSeconds) override;

	virtual void PhysCustom(float deltaTime, int32 Iterations) override;

	bool IsVelocityTowardsWall(FHitResult WallToCheck);

	//custom movement mode

	virtual void PhysWalking(float deltaTime, int32 Iterations) override;
	virtual void PhysFalling(float deltaTime, int32 Iterations) override;

	UPROPERTY(BlueprintReadWrite) float skateGravity = 1000;

	bool TryWallRun();
	bool TryRailGrind();
	void PhysWallRun(float deltaTime, int32 Iterations);
	void PhysRailGrind(float deltaTime, int32 Iterations);

	bool TryWallRunImp1(FHitResult Storedhit);
	bool TryWallRunImp2(FHitResult Storedhit);

	


	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;
};


