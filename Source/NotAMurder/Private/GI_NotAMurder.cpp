// Fill out your copyright notice in the Description page of Project Settings.

#include "GI_NotAMurder.h"
#include "Kismet/GameplayStatics.h"
#include <algorithm>



UGI_NotAMurder::UGI_NotAMurder()
{
	Levels = {TEXT("Level1"), TEXT("Level2"), TEXT("Level3"), TEXT("Level4"), TEXT("Level5"), TEXT("Level6")};
}

void UGI_NotAMurder::SaveData(const FString& LevelName, const int32 HighestScore, const int32 HighestRank)
{
	USaveGame_NotAMurder* SaveGameInstance = nullptr;

	// Check if the save game exists
	if (UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		// Load existing save game
		SaveGameInstance = Cast<USaveGame_NotAMurder>(UGameplayStatics::LoadGameFromSlot(SlotName, UserIndex));
	}

	// If no save game exists, create a new one
	if (!SaveGameInstance)
	{
		SaveGameInstance = Cast<USaveGame_NotAMurder>(UGameplayStatics::CreateSaveGameObject(USaveGame_NotAMurder::StaticClass()));
	}

	// Update the highest score and rank if the current score and rank are higher
	if(SaveGameInstance->LevelsData.Contains(LevelName))
	{
		// Update the highest score and rank
		SaveGameInstance->LevelsData[LevelName].HighestScore = std::max(SaveGameInstance->LevelsData[LevelName].HighestScore, HighestScore);
		SaveGameInstance->LevelsData[LevelName].HighestRank = std::max(SaveGameInstance->LevelsData[LevelName].HighestRank, HighestRank);
	} else
	{
		// Create a new entry for the level
		FLevelData LevelData;
		LevelData.HighestScore = HighestScore;
		LevelData.HighestRank = HighestRank;
		SaveGameInstance->LevelsData.Add(LevelName, LevelData);
	}


	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, UserIndex);
}

FLevelData UGI_NotAMurder::LoadData(const FString& LevelName)
{
	
	if (UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		USaveGame_NotAMurder* SaveGameInstance = Cast<USaveGame_NotAMurder>(UGameplayStatics::LoadGameFromSlot(SlotName, UserIndex));
		if (SaveGameInstance && SaveGameInstance->LevelsData.Contains(LevelName))
		{
			return SaveGameInstance->LevelsData[LevelName];
		}
	}

	// Return default LevelData if not found
	return FLevelData();
}

void UGI_NotAMurder::ResetData()
{
	if(UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		if(USaveGame_NotAMurder* SaveGameInstance = Cast<USaveGame_NotAMurder>(UGameplayStatics::LoadGameFromSlot(SlotName, UserIndex)))
		{
			for(auto& LevelData : SaveGameInstance->LevelsData)
			{
				// Reset to defaults
				LevelData.Value = FLevelData();
			}
			
			// Save the updated data back to the slot
			UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, UserIndex);
		}

	}
}