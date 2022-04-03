// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnotherDay/Weapons/Weapon.h"
#include "AnotherDay/Weapons/Projectile.h"
#include "GameFramework/Character.h"
#include "APlayerShip.generated.h"

USTRUCT(BlueprintType)
struct FShipWeapon
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float RotationOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	TArray<FName> Turrets;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	TSubclassOf<AProjectile> Type;
};

UCLASS()
class ANOTHERDAY_API AAPlayerShip : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ship")
	int Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FShipWeapon Weapon1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FShipWeapon Weapon2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FShipWeapon Weapon3;

	// Sets default values for this character's properties
	AAPlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
