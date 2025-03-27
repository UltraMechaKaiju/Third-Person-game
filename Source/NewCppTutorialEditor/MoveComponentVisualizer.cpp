// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponentVisualizer.h"
#include "NewCppTutorial/CustomMoveComponent.h"

void FMoveComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	//const AXpCharacter* MoveComponent = Cast<AXpCharacter>(Component);
	//if (MoveComponent)
	//{
	//	MoveComponent->GetMovementComponent();


	//	/*PDI->DrawLine
	//	(
	//		MoveComponent->GetComponentLocation(),
	//		MoveComponent->GetComponentLocation() + MoveComponent->MoveOffset,
	//		FLinearColor::Red,
	//		SDPG_Foreground
	//	);*/

	//	FVector TraceDirection = ((FVector(-450, 40, 132) + FVector::ForwardVector * 15));

	//	PDI->DrawLine
	//	(
	//		FVector(-450, 40, 132), TraceDirection.RotateAngleAxis(30, FVector::UpVector), FColor::Red, SDPG_Foreground
	//	);
	//}
}