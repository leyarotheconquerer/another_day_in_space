// Copyright Epic Games, Inc. All Rights Reserved.


#include "AnotherDayGameModeBase.h"

#include "Kismet/GameplayStatics.h"

AAnotherDayGameModeBase::AAnotherDayGameModeBase()
{
	Wave = 0;
}

void AAnotherDayGameModeBase::BeginPlay()
{
	Wave = 0;
	startTime = GetGameTimeSinceCreation();
}

float AAnotherDayGameModeBase::TotalTime()
{
	return GetGameTimeSinceCreation() - startTime;
}


void AAnotherDayGameModeBase::AddKill(const AEnemyShip* enemy)
{
	UE_LOG(LogTemp, Display, TEXT("Added a kill (1 of %d remaining)"), enemies);
	KillCount.FindOrAdd(enemy->GetClass(), 0)++;
	enemies--;
	if (enemies <= 0)
	{
		UE_LOG(LogTemp, Display, TEXT("No enemies remain, trigger next wave"));
		DisplayWave(Wave);
		StartWave();
	}
}

void AAnotherDayGameModeBase::StartWave()
{
	UE_LOG(LogTemp, Display, TEXT("Wave number %d"), Wave);
	Wave++;
	const int count = Wave;
	TArray<AActor*> spawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnVolume, spawns);
	UE_LOG(LogTemp, Display, TEXT("Here we are finding %s %d"), *SpawnVolume->GetName(), spawns.Num());
	if (spawns.Num() > 0)
	{
		for (int i = 0; i < count; i++)
		{
			AActor* spawn = spawns[FMath::RandHelper(spawns.Num())];
			TSubclassOf<AEnemyShip> type = EnemyTypes[FMath::RandHelper(EnemyTypes.Num())];
			FVector origin;
			FVector extent;
			spawn->GetActorBounds(false, origin, extent);
			FVector location = origin + FVector(
				FMath::RandRange(0.f, extent.X),
				FMath::RandRange(0.f, extent.Y),
				0.f
			);
			location.Z = 0;
			AActor* actor = GetWorld()->SpawnActor<AEnemyShip>(type, location, FRotator{});
			if (actor != nullptr)
			{
				enemies += 1;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to find spawns"));
	}
}
