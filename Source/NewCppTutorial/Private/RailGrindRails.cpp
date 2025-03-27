// Fill out your copyright notice in the Description page of Project Settings.


#include "RailGrindRails.h"

// Sets default values
ARailGrindRails::ARailGrindRails()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	GrindRail = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	RootComponent = GrindRail;
}

FVector ARailGrindRails::GetGrindSplineClosestLocation(FVector FootLocation)
{
	return GrindRail->FindLocationClosestToWorldLocation(FootLocation, ESplineCoordinateSpace::World);
}

// Called when the game starts or when spawned
void ARailGrindRails::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARailGrindRails::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

