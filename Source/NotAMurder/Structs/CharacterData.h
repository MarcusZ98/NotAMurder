// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NotAMurder/Enums/CharacterType.h"
#include "CharacterData.generated.h"

class ABaseWeapon;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	TSubclassOf<ABaseWeapon> Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	ABaseWeapon* WeaponInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	TSubclassOf<ABaseWeapon> SecondaryWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	ABaseWeapon* SecondaryWeaponInstance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float DamageMultiplier;
	

	FCharacterData():
	MaxHealth(100.0f),
	CurrentHealth(MaxHealth),
	MovementSpeed(700.0f),
	CharacterType(ECharacterType::None),
	Weapon(nullptr),
	WeaponInstance(nullptr),
	DamageMultiplier(1.0) {}
};
