// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "SpawnBox.generated.h"



UCLASS()
class NEWCPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool SpawnActor();


	void ScheduleActorSpawn();

	UFUNCTION(BlueprintCallable)
	void EnableActorSpawning(bool Enable);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorToBeSpawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnOffset = 1.f;




private:
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	UFUNCTION()
	void SpawnAndSchedule();

	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = true;

	FTimerHandle SpawnTimerHandle;
};
