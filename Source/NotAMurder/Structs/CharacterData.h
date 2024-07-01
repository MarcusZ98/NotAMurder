// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NotAMurder/Enums/CharacterType.h"
#include "CharacterData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxHealth;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Attributes")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	ECharacterType CharacterType;
	

	FCharacterData(): MaxHealth(100.0f), CurrentHealth(100.0f), MovementSpeed(700.0f), CharacterType(ECharacterType::None){}
};
