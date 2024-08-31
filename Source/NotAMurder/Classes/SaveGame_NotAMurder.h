// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGame_NotAMurder.generated.h"

USTRUCT(BlueprintType)
struct FLevelData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Level Data")
	int32 HighestScore = 0;
	
	UPROPERTY(BlueprintReadWrite, Category = "Level Data")
	int32 HighestRank = 0;

};


UCLASS()
class NOTAMURDER_API USaveGame_NotAMurder : public USaveGame
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintReadWrite, Category = "SaveGame")
	TMap<FString, FLevelData> LevelsData;
	
};



