// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController_NotAMurder.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"




APlayerController_NotAMurder::APlayerController_NotAMurder()
{
	bShouldPerformFullTickWhenPaused = true;
}

void APlayerController_NotAMurder::BeginPlay()
{
	Super::BeginPlay();

    PauseMenuClass = StaticLoadClass(UUserWidget::StaticClass(), nullptr, TEXT("/Game/NotAMurder/Blueprints/Widgets/WBP_PauseScreen.WBP_PauseScreen_C"));
	if (PauseMenuClass)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Widget Successfully Found"));
	}
}

void APlayerController_NotAMurder::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Pause", IE_Pressed, this, &APlayerController_NotAMurder::TogglePauseMenu);
}


void APlayerController_NotAMurder::TogglePauseMenu()
{
	if(const UWorld* World = GetWorld())
	{
		const bool bIsPaused = UGameplayStatics::IsGamePaused(World);
		UGameplayStatics::SetGamePaused(World, !bIsPaused);
		
		if (bIsPaused)
		{
			// Unpausing the game
			if (PauseMenu)
			{
				PauseMenu->RemoveFromParent();
				PauseMenu = nullptr;
				CurrentMouseCursor = EMouseCursor::Default;
			}
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Game Unpaused"));
		}
		else
		{
			// Pausing the game
			if (PauseMenuClass)
			{
				PauseMenu = CreateWidget<UUserWidget>(this, PauseMenuClass);
				if (PauseMenu)
				{
					PauseMenu->AddToViewport();
					CurrentMouseCursor = EMouseCursor::Hand;
					
				}
			}
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Game Paused"));
		}



		
	}

}

void APlayerController_NotAMurder::CreatePauseMenu()
{
	if (PauseMenuClass)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, PauseMenuClass);
			
		if(PauseMenu)
		{
			PauseMenu->AddToViewport();
		}
	}	
}
