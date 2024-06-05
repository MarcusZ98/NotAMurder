// Copyright Epic Games, Inc. All Rights Reserved.

#include "NotAMurderGameMode.h"
#include "NotAMurderCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANotAMurderGameMode::ANotAMurderGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
