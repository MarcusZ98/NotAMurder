// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_NotAMurder.generated.h"

/**
 * 
 */
UCLASS()
class NOTAMURDER_API UGI_NotAMurder : public UGameInstance
{
	GENERATED_BODY()

public:

	///////////////////// Variables for the settings ///////////////////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float Sensitivity = 20.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	int32 TextureQuality = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	int32 ShadowQuality = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	int32 ViewDistance = 1;
};
