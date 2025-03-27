// Fill out your copyright notice in the Description page of Project Settings.

#include "XpCharacter.h"
#include "CustomMoveComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomMeshComponent.h"
#include "RailGrindRails.h"

// Sets default values
/**/


AXpCharacter::AXpCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomMoveComponent>(ACharacter::CharacterMovementComponentName))
{
	MovementComponent = Cast<UCustomMoveComponent>(GetCharacterMovement());

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetCapsuleComponent());

	GrindRailHitBoxContainer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GRHBC"));
	GrindRailHitBoxContainer->SetupAttachment(GetCapsuleComponent());

	Springarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Springarm->SetupAttachment(GetCapsuleComponent());
	
	Springarm->SocketOffset.Z = 75;
	Springarm->bUsePawnControlRotation = true;
	Springarm->bInheritPitch = true;
	Springarm->bInheritYaw = true;
	Springarm->bInheritRoll = true;
	Springarm->bEnableCameraRotationLag = false;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(Springarm,USpringArmComponent::SocketName);
}

TArray<AActor*> AXpCharacter::GetRailGrindHitBoxOverlapped(){
	TArray<AActor*> Overlapped;
	Overlapped.Empty();
	GrindRailHitBoxContainer->GetOverlappingActors(Overlapped,ARailGrindRails::StaticClass());
	return Overlapped;
}

// Called when the game starts or when spawned
void AXpCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}


	GetCharacterMovement()->MaxCustomMovementSpeed = 500;
	//GetCharacterMovement()->JumpZVelocity = x;

	

}

// Called every frame
void AXpCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input

void AXpCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AXpCharacter::EnhancedMovement);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AXpCharacter::JumpMovement);
		EnhancedInputComponent->BindAction(Look, ETriggerEvent::Triggered, this, &AXpCharacter::CameraControl);
	}
}

void AXpCharacter::EnhancedMovement(const FInputActionValue& value)
{
	FVector CameraForward = (GetCapsuleComponent()->GetComponentLocation() - Springarm->GetSocketLocation(Springarm->SocketName)).GetSafeNormal2D();

	DrawDebugLine(GetWorld(), GetCapsuleComponent()->GetComponentLocation(), GetCapsuleComponent()->GetComponentLocation() + CameraForward * 100, FColor::Blue, false);

	float CorrectionRads = FMath::Acos(FVector::BackwardVector | CameraForward );

	float DegreesFromLeft = FMath::RadiansToDegrees(FMath::Acos(FVector::RightVector | CameraForward ));

	FVector2D vec = value.Get<FVector2D>();

	FVector Direction = FVector(vec.X, vec.Y, 0);

	if (DegreesFromLeft >= 90) {
		Direction = (Direction.GetSafeNormal()).RotateAngleAxisRad(CorrectionRads, FVector::UpVector);
	}
	else {
		Direction = (Direction.GetSafeNormal()).RotateAngleAxisRad(-CorrectionRads, FVector::UpVector);
	}
	

	AddMovementInput(Direction, 1);
}

void AXpCharacter::JumpMovement(const FInputActionValue& value)
{
	if (value.Get<bool>()) {
		Super::Jump();
	}
	if (!value.Get<bool>()) {
		Super::StopJumping();
	}
}

void AXpCharacter::CameraControl(const FInputActionValue& value)
{
	FVector2D MouseInput = value.Get<FVector2D>();
	AddControllerYawInput(MouseInput.X);
	AddControllerPitchInput(-MouseInput.Y);
}



FCollisionQueryParams AXpCharacter::GetIgnoreCharacterParams() const
{
	FCollisionQueryParams Params;

	TArray<AActor*> CharacterChildren;
	GetAllChildActors(CharacterChildren);
	Params.AddIgnoredActors(CharacterChildren);
	Params.AddIgnoredActor(this);

	return Params;
}

FComponentQueryParams AXpCharacter::GetIgnoreCharacterComponentParams() const
{
	FComponentQueryParams SelfC;

	TArray<UPrimitiveComponent*> SelfComps;
	GetComponents(SelfComps);

	SelfC.AddIgnoredComponents(SelfComps);
	
	return SelfC;
}

FVector AXpCharacter::GetCameraDirection()
{
	return (GetCapsuleComponent()->GetComponentLocation() - Springarm->GetSocketLocation(Springarm->SocketName)).GetSafeNormal2D();
}
