// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentEndPointReachedSignature, bool, IsTopEndpoint);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWCPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	UFUNCTION(BlueprintCallable)
	void MoveReset();

	UFUNCTION(BlueprintCallable)
	void SetDirection(int Direction);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame


	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private:

	friend class FMoveComponentVisualizer;

	UPROPERTY(EditAnywhere)
	float Speed = 1.f;


	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentEndPointReachedSignature OnEndPointReached;

	float CurrentDistance;
	FVector MoveOffsetNorm;
	float MaxDistance;
	float MoveDirection = 1.f;

	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	FVector StartRelativeLocation;

	UPROPERTY (EditAnywhere)
	bool MoveEnable;

		
};
