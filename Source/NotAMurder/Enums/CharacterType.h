// CharacterType.h
#pragma once

#include "UObject/ObjectMacros.h"
#include "CharacterType.generated.h"

UENUM(BlueprintType)
enum class ECharacterType : uint8
{
	None UMETA(DisplayName = "None"),
	Player UMETA(DisplayName = "Player"),
	Enemy UMETA(DisplayName = "Enemy")
};
