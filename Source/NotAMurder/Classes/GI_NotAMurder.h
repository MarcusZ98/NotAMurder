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

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Level")
	FName DesiredLevelName;
	
};
