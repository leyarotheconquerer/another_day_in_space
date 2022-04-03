// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	NORMAL = 0 UMETA(DisplayName = "Normal"),
	BEAM = 1 UMETA(DisplayName = "Beam"),
	MISSILE = 2 UMETA(DisplayName = "Missile")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthEvent);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ANOTHERDAY_API UHealth : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Armor")
	float Armor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Armor")
	float ArmorTotal;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shield")
	float Shield;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shield")
	float ShieldTotal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	TMap<TSubclassOf<UDamageType>, EDamageType> DamageTypes;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FHealthEvent Die;
	
	// Sets default values for this component's properties
	UHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(
		float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

	UFUNCTION(BlueprintCallable, Category="Health")
	void TakeDamage(float damage, const UDamageType* type);

	// UFUNCTION(BlueprintImplementableEvent, Category="Health")
	// void Die();
};
