// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	CharacterData.CharacterType = ECharacterType::Enemy;
}

void AEnemyCharacter::KillEnemy_Implementation()
{
	Destroy();
}

void AEnemyCharacter::Shoot_Implementation()
{
	
}

void AEnemyCharacter::TakeDamage_Implementation(float Damage)
{
	
}

void AEnemyCharacter::SetEnemyData_Implementation(const FEnemyData& NewData)
{
	EnemyData = NewData;
}

FEnemyData AEnemyCharacter::GetEnemyData_Implementation()
{
	return EnemyData;
}
