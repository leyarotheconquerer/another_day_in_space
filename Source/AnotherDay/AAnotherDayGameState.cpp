// Fill out your copyright notice in the Description page of Project Settings.


#include "AAnotherDayGameState.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AAAnotherDayGameState::AAAnotherDayGameState()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	enemies = 0;
	Wave = 0;
}

// Called when the game starts or when spawned
void AAAnotherDayGameState::BeginPlay()
{
	Super::BeginPlay();
	Wave = 0;
	startTime = GetGameTimeSinceCreation();
}

// Called every frame
void AAAnotherDayGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AAAnotherDayGameState::TotalTime()
{
	return GetGameTimeSinceCreation() - startTime;
}


void AAAnotherDayGameState::AddKill(const AEnemyShip* enemy)
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

void AAAnotherDayGameState::StartWave()
{
	UE_LOG(LogTemp, Display, TEXT("Wave number %d"), Wave);
	Wave++;
	const int count = Wave;
	AAnotherDayGameModeBase* mode = Cast<AAnotherDayGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (mode == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Game state failed to find game mode"));
		return;
	}
	TArray<AActor*> spawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), mode->SpawnVolume, spawns);
	UE_LOG(LogTemp, Display, TEXT("Here we are finding %s %d"), *mode->SpawnVolume->GetName(), spawns.Num());
	if (spawns.Num() > 0)
	{
		for (int i = 0; i < count; i++)
		{
			AActor* spawn = spawns[FMath::RandHelper(spawns.Num())];
			TSubclassOf<AEnemyShip> type = mode->EnemyTypes[FMath::RandHelper(mode->EnemyTypes.Num())];
			FVector extent;
			FVector origin;
			spawn->GetActorBounds(false, origin, extent);
			FVector location = origin + FVector(
				FMath::RandRange(0.f, extent.X),
				FMath::RandRange(0.f, extent.Y),
				0.f
			);
			location.Z = 0;
			AActor* actor = GetWorld()->SpawnActor<AEnemyShip>(type, location, FRotator{0.f, 0.f, 0.f});
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
