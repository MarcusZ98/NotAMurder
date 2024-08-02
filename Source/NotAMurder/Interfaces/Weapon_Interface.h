// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "UObject/Interface.h"
#include "Weapon_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NOTAMURDER_API IWeaponInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void FireWeapon(ABaseCharacter* OwnerOfWeapon, const FVector& StartLocation, const FVector& ForwardVector,USceneComponent* HitTarget);
	virtual void FireWeapon_Implementation(ABaseCharacter* OwnerOfWeapon, const FVector& StartLocation, const FVector& ForwardVector, USceneComponent* HitTarget) = 0;

};
