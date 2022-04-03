// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector forward = GetActorForwardVector() * DeltaTime * Speed;
	AddActorWorldOffset(forward, true);
	if (GetGameTimeSinceCreation() > Lifetime)
	{
		UE_LOG(LogTemp, Display, TEXT("Test message"));
		Expire();
	}
}

void AProjectile::SetTargets(const TArray<TSubclassOf<AActor>> targets)
{
	Targets.Empty();
	for (TSubclassOf<AActor> target : targets)
	{
		Targets.Add(target);
	}
}


void AProjectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	const UClass* otherType = OtherActor->GetClass();
	for (const UClass* targetType : Targets)
	{
		if (otherType->IsChildOf(targetType))
		{
			const float resultingDamage = OtherActor->TakeDamage(
				Damage, FDamageEvent(Type),
				GetInstigatorController(), GetInstigator()
			);
			Collide();
			break;
		}
	}
}
