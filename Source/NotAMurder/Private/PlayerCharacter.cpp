// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "PlayerController_NotAMurder.h"
#include "Kismet/GameplayStatics.h"


APlayerCharacter::APlayerCharacter(){
	CharacterData.CharacterType = ECharacterType::Player;
}


