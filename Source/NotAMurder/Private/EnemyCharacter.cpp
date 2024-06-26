// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	CharacterType = ECharacterType::Enemy;

	EnemyData.Health = 100.0f;
	EnemyData.DamageMultiplier = 1.0f;
	EnemyData.Mesh = nullptr;
	EnemyData.AnimationBlueprintClass = nullptr;
}

void AEnemyCharacter::KillEnemy_Implementation()
{
	Destroy();
}

void AEnemyCharacter::Shoot_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy is shooting"));
}

void AEnemyCharacter::TakeDamage_Implementation(float Damage)
{
	EnemyData.Health -= Damage;
	if (EnemyData.Health <= 0)
	{
		KillEnemy();
	}
}

void AEnemyCharacter::ApplyNewData_Implementation(const FEnemyData& NewData)
{
	EnemyData = NewData;
}

