// Fill out your copyright notice in the Description page of Project Settings.


#include "NotAMurderGameState.h"
#include "GI_NotAMurder.h"
#include "GameFramework/GameUserSettings.h"


void ANotAMurderGameState::BeginPlay()
{
	Super::BeginPlay();


	//////////// Set the game settings ////////////
	UGameUserSettings* UserSettings = GEngine->GameUserSettings;
	UGI_NotAMurder* GameInstance = Cast<UGI_NotAMurder>(GetGameInstance());
	
	if(UserSettings && GameInstance)
	{
		// Set the sensitivity
			// Do what you gotta do Fabio


		// Set the texture quality
		UserSettings->SetTextureQuality(GameInstance->TextureQuality);

		// Set the shadow quality
		UserSettings->SetShadowQuality(GameInstance->ShadowQuality);

		//Set the view distance
		UserSettings->SetViewDistanceQuality(GameInstance->ViewDistance);
		FString ShadowQualityString = FString::Printf(TEXT("Shadow Quality: %d"), GameInstance->ShadowQuality);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, ShadowQualityString);

	}
}
