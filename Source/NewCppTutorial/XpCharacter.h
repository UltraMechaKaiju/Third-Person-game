// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Engine/StaticMesh.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

#include "Engine/LocalPlayer.h"
#include "CustomMeshComponent.h"


#include "XpCharacter.generated.h"


UCLASS()
class NEWCPPTUTORIAL_API AXpCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	//AXpCharacter();
	AXpCharacter(const FObjectInitializer& ObjectInitializer);

	int count = 0;
	
	TArray<AActor*> GetRailGrindHitBoxOverlapped();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(/*EditDefaultsOnly, BlueprintReadWrite,*/BlueprintReadWrite, Category = Movement)
	class UCustomMoveComponent* MovementComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FCollisionQueryParams GetIgnoreCharacterParams() const;
	FComponentQueryParams GetIgnoreCharacterComponentParams() const;
	FVector GetCameraDirection();

	UPROPERTY(BlueprintReadWrite, Category = "CustomMesh")
	UCustomMeshComponent* ScanTriangle1;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* Springarm;

	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	UCameraComponent* PlayerCamera;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* GrindRailHitBoxContainer;

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* TestHitBox;

	UFUNCTION(BlueprintCallable)

	/*void MoveFB(float Value);

	void MoveLR(float Value);

	void Rotate(float Value);*/

	void EnhancedMovement(const FInputActionValue& value);
	void JumpMovement(const FInputActionValue& value);
	void CameraControl(const FInputActionValue& value);

	/*UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;*/

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Look;
};
