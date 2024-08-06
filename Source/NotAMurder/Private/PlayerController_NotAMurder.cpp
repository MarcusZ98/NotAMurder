// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController_NotAMurder.h"

void APlayerController_NotAMurder::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("IA_Pause", IE_Pressed, this, &APlayerController::Pause);
}


