// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "Weapon.generated.h"

USTRUCT(BlueprintType)
struct FWeaponStatus
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	bool CanFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float RemainingTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float TotalTime;
};

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ANOTHERDAY_API UWeapon : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float RotationOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	TArray<FName> Turrets;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	TSubclassOf<AProjectile> Type;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	TArray<TSubclassOf<AActor>> Targets;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float FireDelay;

	UWeapon();

protected:
	float lastFired;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(
		float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire(UMeshComponent* mesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Weapon")
	FWeaponStatus GetStatus();
};
