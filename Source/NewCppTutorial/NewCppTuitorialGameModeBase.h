// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"

#include "XpPawn.h"

#include "NewCppTuitorialGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class NEWCPPTUTORIAL_API ANewCppTuitorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void InitGameState() override;

private:
	 UPROPERTY(EditAnywhere, NoClear)
	 TSubclassOf<AXpPawn> CustomXpPawn = AXpPawn::StaticClass();


	 //Tsubclassof means you can pick any sunbclass of the selected class or the class itself



};
