// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NotAMurder/Structs/CharacterData.h"
#include "UObject/Interface.h"
#include "Character_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacter_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NOTAMURDER_API ICharacter_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character")
	FCharacterData GetCharacterData();
	virtual FCharacterData GetCharacterData_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character")
	void SetCharacterData(const FCharacterData& NewData);
	virtual void SetCharacterData_Implementation(const FCharacterData& NewData) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character")
	ECharacterType GetCharacterType();
	virtual ECharacterType GetCharacterType_Implementation() = 0;
};
