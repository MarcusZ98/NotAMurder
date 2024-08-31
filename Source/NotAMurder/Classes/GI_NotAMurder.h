// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SaveGame_NotAMurder.h"
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

	UGI_NotAMurder();


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Levels")
	TArray<FString> Levels; 

	///////////////////// Variables for the settings ///////////////////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float Sensitivity = 20.0f;




	///////////////////// Handling Save/Load ///////////////////////

public:
	
	// Save game data
	UFUNCTION(BlueprintCallable, Category = "Save/Load")
	void SaveData(const FString& LevelName, const int32 HighestScore, const int32 HighestRank);

	// Load game data
	UFUNCTION(BlueprintCallable, Category = "Save/Load")
	FLevelData LoadData(const FString& LevelName);

	// Reset save game data
	UFUNCTION(BlueprintCallable, Category = "Save/Load")
	void ResetData();


private:

	UPROPERTY()
	FString SlotName = TEXT("LevelDataSlot");

	UPROPERTY()
	int32 UserIndex = 0;
	
};
