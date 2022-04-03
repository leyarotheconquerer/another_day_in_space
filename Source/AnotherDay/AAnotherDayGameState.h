// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnotherDayGameModeBase.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameState.h"
#include "Ships/EnemyShip.h"
#include "AAnotherDayGameState.generated.h"

UCLASS()
class ANOTHERDAY_API AAAnotherDayGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level")
	int Wave;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Score")
	TMap<TSubclassOf<AEnemyShip>, int> KillCount;
	
	// Sets default values for this actor's properties
	AAAnotherDayGameState();

protected:
	float startTime;
	int enemies;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Score")
	float TotalTime();
	
	UFUNCTION(BlueprintCallable, Category="Score")
	void AddKill(const AEnemyShip* enemy);

	UFUNCTION(BlueprintCallable, Category="Level")
	void StartWave();

	UFUNCTION(BlueprintImplementableEvent, Category="Level")
	void DisplayWave(int number);
};
