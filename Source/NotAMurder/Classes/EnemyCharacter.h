// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "NotAMurder/Interfaces/Enemy_Interface.h"
#include "NotAMurder/Structs/EnemyData.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	Default UMETA(DisplayName = "Default"),
	Melee UMETA(DisplayName = "Melee"),
	Ranged UMETA(DisplayName = "Ranged"),
	Boss UMETA(DisplayName = "Boss")
};

UCLASS()
class NOTAMURDER_API AEnemyCharacter : public ABaseCharacter, public IEnemy_Interface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FEnemyData EnemyData;

	UFUNCTION(BlueprintCallable, Category = "Enemy")
	virtual void KillEnemy_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Enemy")
	virtual void Shoot_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Enemy")
	virtual void TakeDamage_Implementation(float Damage) override;

	UFUNCTION(BlueprintCallable, Category = "Enemy")
	virtual void ApplyNewData_Implementation(const FEnemyData& NewData) override;
	
};
