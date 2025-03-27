// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Engine/StaticMesh.h"

#include "Camera/CameraComponent.h"

#include "XpPawn.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API AXpPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AXpPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;

	void MoveFB(float Value);

	void MoveLR(float Value);
	
	void Rotate(float Value);

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;

};
