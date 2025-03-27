// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacter.h"


#include "CustomMoveComponent.h"

// Sets default values
ACustomCharacter::ACustomCharacter(const FObjectInitializer& ObjectInitializer)
	: Super (ObjectInitializer.SetDefaultSubobjectClass<UCustomMoveComponent>(ACharacter::CharacterMovementComponentName))
{
	MovementComponent = Cast<UCustomMoveComponent>(GetCharacterMovement());

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetCapsuleComponent());
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(GetCapsuleComponent());

	GetCharacterMovement()->bOrientRotationToMovement = false;
}

// Called when the game starts or when spawned
void ACustomCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ACustomCharacter::EnhancedMovement);
	}
}

void ACustomCharacter::MoveFB(float Value)
{
	AddMovementInput(-GetActorForwardVector(), Value);
}

void ACustomCharacter::MoveLR(float Value)
{
	AddMovementInput(-GetActorRightVector(), Value);
}

void ACustomCharacter::EnhancedMovement(const FInputActionValue& value)
{
	FVector2D vec = value.Get<FVector2D>();

	FVector Direction = FVector(vec.X, vec.Y, 0);

	Direction = Direction.GetSafeNormal();

	AddMovementInput(Direction, 1);

	UE_LOG(LogTemp, Warning, TEXT("Success"));
}

