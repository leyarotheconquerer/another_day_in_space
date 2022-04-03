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
	TSubclassOf<AActor> SpawnVolume;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level")
	TArray<TSubclassOf<AEnemyShip>> EnemyTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	TMap<TSubclassOf<UDamageType>, FDamageFactor> DamageTypes;

	AAnotherDayGameModeBase();

public:
	virtual void BeginPlay() override;
};
