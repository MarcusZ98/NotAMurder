// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	CharacterData.CharacterType = ECharacterType::Enemy;

	// Initialize the static mesh component
	ShootStartLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	ShootStartLocation->SetupAttachment(RootComponent);

	// Find the sphere mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (SphereMeshAsset.Succeeded())
	{
		// Set the static mesh component to use the sphere mesh
		ShootStartLocation->SetStaticMesh(SphereMeshAsset.Object);
		ShootStartLocation->SetHiddenInGame(true);
	}
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
	
}

void AEnemyCharacter::SetEnemyData_Implementation(const FEnemyData& NewData)
{
	EnemyData = NewData;
}

FEnemyData AEnemyCharacter::GetEnemyData_Implementation()
{
	return EnemyData;
}
