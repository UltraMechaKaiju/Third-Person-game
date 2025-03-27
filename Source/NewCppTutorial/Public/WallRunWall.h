// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "Engine/StaticMeshActor.h"
#include "WallRunWall.generated.h"

/**
 * 
 */
UCLASS()
class NEWCPPTUTORIAL_API AWallRunWall : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AWallRunWall();

	virtual void BeginPlay() override;

protected:
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer WallRunWallTags;*/
};
