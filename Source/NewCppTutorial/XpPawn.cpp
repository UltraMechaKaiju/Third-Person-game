// Fill out your copyright notice in the Description page of Project Settings.


#include "XpPawn.h"

// Sets default values
AXpPawn::AXpPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(PlayerMesh);

}

// Called when the game starts or when spawned
void AXpPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXpPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXpPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXpPawn::MoveFB);

	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXpPawn::MoveLR);
	
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXpPawn::Rotate);

}

void AXpPawn::MoveFB(float Value)
{
	auto Location = GetActorLocation();
	Location += GetActorForwardVector() *Value * MoveSpeed * -1;
	SetActorLocation(Location);
}

void AXpPawn::MoveLR(float Value)
{
	auto Location = GetActorLocation();
	Location += GetActorRightVector() * Value * MoveSpeed * -1;
	SetActorLocation(Location);
}

void AXpPawn::Rotate(float Value)
{
	auto Rotation = GetActorRotation();
	Rotation.Yaw += Value * RotationSpeed;
	SetActorRotation(Rotation);
}
