// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"

#include "AnotherDayGameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UHealth::UHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Shield = ShieldTotal = 100.f;
	Armor = ArmorTotal = 100.f;
	ShieldRegen = 10.f;
	ShieldRegenRate = 1.f;
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();
	AAnotherDayGameModeBase* mode = Cast<AAnotherDayGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	lastRegen = GetOwner()->GetGameTimeSinceCreation();
	if (mode != nullptr)
	{
		DamageTypes.Empty();
		DamageTypes.Append(mode->DamageTypes);
	}
}


// Called every frame
void UHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float now = GetOwner()->GetGameTimeSinceCreation();
	if (lastRegen + ShieldRegenRate < now)
	{
		Shield = FMath::Min(Shield + ShieldRegen, ShieldTotal);
		lastRegen = now;
	}
}


void UHealth::TakeDamage(float damage, const UDamageType* type)
{
	const TSubclassOf<UDamageType> typeClass = type->GetClass();
	if (DamageTypes.Contains(typeClass))
	{
		const FDamageFactor* factor = DamageTypes.Find(typeClass);
		if (factor != nullptr)
		{
			const float remaining = FMath::Max(0.f, (damage * factor->ShieldFactor - Shield) / factor->ShieldFactor);
			Shield = FMath::Max(0.f, Shield - damage * factor->ShieldFactor);
			Armor = FMath::Max(0.f, Armor - remaining * factor->ShieldFactor);
			if (Armor <= 0.001f)
			{
				Die.Broadcast();
			}
		}
	}
}
