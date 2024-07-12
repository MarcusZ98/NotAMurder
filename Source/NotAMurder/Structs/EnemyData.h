// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FEnemyData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float DamageMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float DamagePerShot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 PointsWorth;

	FEnemyData(): DamageMultiplier(1.0f), PointsWorth(1000), DamagePerShot(25){}
};
