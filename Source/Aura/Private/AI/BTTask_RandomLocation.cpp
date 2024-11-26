// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_RandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

UBTTask_RandomLocation::UBTTask_RandomLocation()
{
	NodeName = "Get Custom_Random Location";
}

EBTNodeResult::Type UBTTask_RandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (TargetPoints.Num() == 0)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);
	}

	if (TargetPoints.Num() == 0)
	{
		return EBTNodeResult::Failed;
	}

	int32 RandomIndex = FMath::RandRange(0, TargetPoints.Num() - 1);
	AActor* RandomTargetPoint = TargetPoints[RandomIndex];

	if (RandomTargetPoint)
	{
		FVector TargetLocation = RandomTargetPoint->GetActorLocation();
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetLocation"), TargetLocation);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
