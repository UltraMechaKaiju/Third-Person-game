// Fill out your copyright notice in the Description page of Project Settings.


#include "NewCppTuitorialGameModeBase.h"

void ANewCppTuitorialGameModeBase::InitGameState()
{
	Super::InitGameState();

	if (DefaultPawnClass == ADefaultPawn::StaticClass())
	{
		DefaultPawnClass = CustomXpPawn;
	}
}