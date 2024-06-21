// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
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
class NOTAMURDER_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();
};
