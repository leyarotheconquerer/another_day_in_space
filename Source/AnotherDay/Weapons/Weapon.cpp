// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

UWeapon::UWeapon()
{
	
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeapon::Fire(UMeshComponent* mesh)
{
	for (const FName name : Turrets)
	{
		UE_LOG(LogTemp, Display, TEXT("Firing %s"), *name.ToString());
		const FVector location = mesh->GetSocketLocation(name);
		const FRotator rotation(
			0.f,
			mesh->GetSocketRotation(name).Yaw + RotationOffset,
			0.f
		);
		const AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Type, location, rotation);
	}
}


