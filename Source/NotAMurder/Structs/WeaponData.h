// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponData.generated.h"

class ABaseProjectile;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 DamagePerShot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes",
		meta = (tooltip = "Seconds between each shot"))
	float FireRate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes")
	TSubclassOf<ABaseProjectile> Projectile;

	FWeaponData(): DamagePerShot(10), FireRate(0.1f), Projectile() {}
};
