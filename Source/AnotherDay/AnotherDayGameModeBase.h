// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ships/EnemyShip.h"
#include "AnotherDayGameModeBase.generated.h"

USTRUCT(BlueprintType)
struct FDamageFactor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float ShieldFactor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float ArmorFactor;
};

/**
 * 
 */
UCLASS()
class ANOTHERDAY_API AAnotherDayGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level")
	int Wave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level")
	TSubclassOf<AActor> SpawnVolume;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level")
	TArray<TSubclassOf<AEnemyShip>> EnemyTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Score")
	TMap<TSubclassOf<AEnemyShip>, int> KillCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	TMap<TSubclassOf<UDamageType>, FDamageFactor> DamageTypes;

	AAnotherDayGameModeBase();

protected:
	float startTime;
	int enemies;

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Score")
	float TotalTime();
	
	UFUNCTION(BlueprintCallable, Category="Score")
	void AddKill(const AEnemyShip* enemy);

	UFUNCTION(BlueprintCallable, Category="Level")
	void StartWave();

	UFUNCTION(BlueprintImplementableEvent, Category="Level")
	void DisplayWave(int number);
};
