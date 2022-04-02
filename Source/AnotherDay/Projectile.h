// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class ANOTHERDAY_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float Lifetime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	TSubclassOf<UDamageType> Type;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	TArray<UClass*> Targets;

	// Sets default values for this actor's properties
	AProjectile();

protected:
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Projectile")
	void Collide();

	UFUNCTION(BlueprintImplementableEvent, Category="Projectile")
	void Expire();
};
