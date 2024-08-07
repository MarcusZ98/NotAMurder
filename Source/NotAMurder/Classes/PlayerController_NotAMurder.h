// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController_NotAMurder.generated.h"

/**
 * 
 */
UCLASS()
class NOTAMURDER_API APlayerController_NotAMurder : public APlayerController
{
	GENERATED_BODY()

public:

	APlayerController_NotAMurder();
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void TogglePauseMenu();

	virtual void BeginPlay() override;

protected:

	UFUNCTION()
	virtual void SetupInputComponent() override;

private:
	UPROPERTY()
	TSubclassOf<UUserWidget> PauseMenuClass;

	UPROPERTY()
	UUserWidget* PauseMenu;

	UFUNCTION()
	void CreatePauseMenu();
};
