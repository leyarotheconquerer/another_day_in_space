// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

UWeapon::UWeapon()
{
	
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();
	lastFired = -100;
}


// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UWeapon::Fire(UMeshComponent* mesh)
{
	if (GetStatus().CanFire)
	{
		lastFired = GetOwner()->GetGameTimeSinceCreation();
		for (const FName name : Turrets)
		{
			const FVector location = mesh->GetSocketLocation(name);
			const FRotator rotation(
				0.f,
				mesh->GetSocketRotation(name).Yaw + RotationOffset,
				0.f
			);
			AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Type, location, rotation);
			if (projectile)
			{
				projectile->SetTargets(Targets);
			}
		}
	}
}

FWeaponStatus UWeapon::GetStatus()
{
	const float currentTime = GetOwner()->GetGameTimeSinceCreation();
	return FWeaponStatus {
		lastFired + FireDelay < currentTime,
		FMath::Max(0.f, lastFired + FireDelay - currentTime),
		FireDelay
	};
}



