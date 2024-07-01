// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileData.h"
#include "WeaponData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 DamagePerShot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FProjectileData ProjectileData;

	FWeaponData(): DamagePerShot(10), FireRate(0.1f){}
};
