// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectileData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FProjectileData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	UNiagaraSystem* ProjectileFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	UNiagaraSystem* ImpactFX;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float ProjectileLife;

	

	FProjectileData(): ProjectileFX(), ImpactFX(), ProjectileSpeed(1000.0f), ProjectileLife(1.0f) {}
};

