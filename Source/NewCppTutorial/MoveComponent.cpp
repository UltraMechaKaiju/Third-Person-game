// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	StartRelativeLocation = GetRelativeLocation();
	
	MoveOffsetNorm = MoveOffset;

	MoveOffsetNorm.Normalize();

	MaxDistance = MoveOffset.Length();

	SetComponentTickEnabled(MoveEnable);
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	
	if (MoveEnable)
	{
		CurrentDistance += DeltaTime * Speed * MoveDirection;
		if (CurrentDistance >= MaxDistance || CurrentDistance <= 0.0f)
		{
			MoveDirection *= -1;

			OnEndPointReached.Broadcast(CurrentDistance >= MaxDistance);

			CurrentDistance = FMath::Clamp(CurrentDistance, 0.0f, MaxDistance);
		}
	}
	
	

	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurrentDistance);

	
}


void UMoveComponent::EnableMovement(bool ShouldMove)
{
	MoveEnable = ShouldMove;
	SetComponentTickEnabled(MoveEnable);

}

void UMoveComponent::MoveReset(){
	CurrentDistance = 0.0f;
	SetRelativeLocation(StartRelativeLocation);
}

void UMoveComponent::SetDirection(int Direction)
{
	MoveDirection = Direction >= 1 ? 1 : -1;
}