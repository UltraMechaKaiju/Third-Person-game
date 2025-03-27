// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "GameFramework/DefaultPawn.h"

#include "MyCollectableActor.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJumpTriggerSignature, class AActor*, OtherActor, class UPrimitiveComponent*, OtherComp);

UCLASS()
class NEWCPPTUTORIAL_API AMyCollectableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCollectableActor();

	UFUNCTION(BlueprintCallable)
	void Jump(float Velocity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, const FHitResult& SweepHitResults);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeTime = 4.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass* TriggerClass = ADefaultPawn::StaticClass();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private :
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;


	bool IsLaunched = false;

	

	

	UPROPERTY(BlueprintAssignable)
	FOnJumpTriggerSignature OnJumpTrigger;

};
