// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NotAMurder/Structs/EnemyData.h"
#include "UObject/Interface.h"
#include "Enemy_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemy_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NOTAMURDER_API IEnemy_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Enemy")
	void KillEnemy();
	virtual void KillEnemy_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Enemy")
	void Shoot();
	virtual void Shoot_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Enemy")
	void TakeDamage(float Damage);
	virtual void TakeDamage_Implementation(float Damage) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Enemy")
	void SetEnemyData(const FEnemyData& NewData);
	virtual void SetEnemyData_Implementation(const FEnemyData& NewData) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Enemy")
	FEnemyData GetEnemyData();
	virtual FEnemyData GetEnemyData_Implementation() = 0;
};
