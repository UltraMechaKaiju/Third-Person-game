// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "RailGrindRails.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API ARailGrindRails : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARailGrindRails();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
	USplineComponent* GrindRail;
	FVector GetGrindSplineClosestLocation(FVector FootLocation);
	//UPROPERTY(VisibleAnywhere, Category = "Custom")
	//USplineMeshComponent* SimpleMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
