// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBox.h"

// Sets default values
ASpawnBox::ASpawnBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;

}

// Called when the game starts or when spawned
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();
	
	if (ShouldSpawn)
	{
		ScheduleActorSpawn();
	}

}

void ASpawnBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

// Called every frame
void ASpawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ASpawnBox::SpawnActor()
{
	bool SpawnedActor = false;
	if (ActorToBeSpawned)
	{
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		FVector SpawnLocation = BoxBounds.Origin;

		SpawnLocation.X += -BoxBounds.BoxExtent.X + BoxBounds.BoxExtent.X * 2 * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + BoxBounds.BoxExtent.Y * 2 * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + BoxBounds.BoxExtent.Z * 2 * FMath::FRand();

		SpawnedActor = GetWorld()->SpawnActor(ActorToBeSpawned, &SpawnLocation) != nullptr; 
	}
	return SpawnedActor;
}

void ASpawnBox::ScheduleActorSpawn()
{
	float DeltaToNextSpawn = AvgSpawnTime + (-RandomSpawnOffset + 2 * RandomSpawnOffset * FMath::FRand());

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnBox::SpawnAndSchedule, DeltaToNextSpawn, false);
}

void ASpawnBox::EnableActorSpawning(bool Enable)
{
	ShouldSpawn = Enable;
	if (Enable) {
		SpawnAndSchedule();
	}
	else {
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
	}
}

void ASpawnBox::SpawnAndSchedule()
{
	SpawnActor();
	if (ShouldSpawn) {
		ScheduleActorSpawn();
	}
}

