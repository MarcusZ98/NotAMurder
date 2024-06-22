// CharacterType.h
#pragma once

#include "UObject/ObjectMacros.h"
#include "CharacterType.generated.h"

UENUM(BlueprintType)
enum class ECharacterType : uint8
{
	Default UMETA(DisplayName = "Default"),
	Player UMETA(DisplayName = "Player"),
	Enemy UMETA(DisplayName = "Enemy")
};
