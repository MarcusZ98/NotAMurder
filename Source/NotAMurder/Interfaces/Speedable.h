// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Speedable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USpeedable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NOTAMURDER_API ISpeedable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Speed")
	float GetOriginalSpeed();
	virtual float GetOriginalSpeed_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Speed")
	float GetCurrentSpeed();
	virtual float GetCurrentSpeed_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Speed")
	void SetCurrentSpeed(const float NewSpeed);
	virtual void SetCurrentSpeed_Implementation(const float NewSpeed) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Speed")
	void SetOriginalSpeed(const float NewSpeed);
	virtual void SetOriginalSpeed_Implementation(const float NewSpeed) = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Speed")
	void MultiplySpeed(const float Multiplier);
	virtual void MultiplySpeed_Implementation(const float Multiplier) = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Speed")
	void ResetSpeed();
	virtual void ResetSpeed_Implementation() = 0;
};
