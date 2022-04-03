// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnotherDay/Weapons/Weapon.h"
#include "GameFramework/Character.h"
#include "EnemyShip.generated.h"

UCLASS()
class ANOTHERDAY_API AEnemyShip : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	UWeapon* Weapon;
	
	// Sets default values for this character's properties
	AEnemyShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Weapon")
	void Attack(FVector target);
};
