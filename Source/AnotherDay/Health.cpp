// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"


// Sets default values for this component's properties
UHealth::UHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UHealth::TakeDamage(float damage, const UDamageType* type)
{
	const TSubclassOf<UDamageType> typeClass = type->GetClass();
	if (DamageTypes.Contains(typeClass))
	{
		EDamageType* damageType = DamageTypes.Find(typeClass);
		float shieldFactor = 1.f;
		float armorFactor = 1.f;
		if (damageType)
		{
			switch (*damageType)
			{
			case EDamageType::BEAM:
				shieldFactor = 2.f;
				armorFactor = 0.5f;
				break;
			case EDamageType::MISSILE:
				shieldFactor = 0.5f;
				armorFactor = 2.f;
				break;
			case EDamageType::NORMAL:
			default:
				break;
			}
		}
		const float remaining = FMath::Max(0.f, (damage * shieldFactor - Shield) / shieldFactor);
		Shield = FMath::Max(0.f, Shield - damage * shieldFactor);
		Armor = FMath::Max(0.f, Armor - remaining * armorFactor);
		if (Armor <= 0.001f)
		{
			Die.Broadcast();
		}
	}
}
