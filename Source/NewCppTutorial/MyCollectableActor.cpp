// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCollectableActor.h"

// Sets default values
AMyCollectableActor::AMyCollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void AMyCollectableActor::BeginPlay()
{
	Super::BeginPlay();
	
	FScriptDelegate DelegateSubscriber;
	DelegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSubscriber);




	SetActorTickEnabled(false);
}

// Called every frame
void AMyCollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{
		if (IsLaunched) {
			LifeTime -= DeltaTime;

			if (LifeTime <= 0.0f)
			{
				Destroy();
			}
		}
	}

}

void AMyCollectableActor::Jump(float Velocity)
{
	if (!IsLaunched)
	{
		SetActorTickEnabled(true);

		StaticMesh->AddImpulse({ .0f, .0f, Velocity * 500.f });

		IsLaunched = true;
	}


	/*auto NewLocation = GetActorLocation();
	NewLocation.Z += Velocity;
	SetActorLocation(NewLocation);*/
}

void AMyCollectableActor::OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, const FHitResult& SweepHitResults)
{
	if (OtherActor->IsA(TriggerClass))
	{
		OnJumpTrigger.Broadcast(OtherActor, Component);
	}
}