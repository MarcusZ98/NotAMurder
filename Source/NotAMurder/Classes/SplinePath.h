// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "NotAMurder/Enums/CharacterType.h"
#include "SplinePath.generated.h"


UCLASS()
class NOTAMURDER_API ASplinePath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplinePath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Spline component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline")
	USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	ECharacterType CharacterType = ECharacterType::Default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Player", meta = (EditCondition = "CharacterType == ECharacterType::Player"))
	AActor* PlayerParent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Custom|Player", meta = (EditCondition = "CharacterType == ECharacterType::Player"))
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy", meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	TSubclassOf<AEnemyCharacter> EnemyClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Custom|Enemy", meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	AActor* EnemyParent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Groups", meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	bool bSpawnGroups = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Groups", meta = (EditCondition = "bSpawnGroups"))
	int32 GroupSize = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Groups", meta = (EditCondition = "bSpawnGroups"))
	float DistanceBetweenEnemies = 150;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Spawning", meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	bool bOnlySpawnOnce = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Spawning", meta = (EditCondition = "!bOnlySpawnOnce"))
	float SpawnInterval = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Spawning", meta = (EditCondition = "!bOnlySpawnOnce"))
	int32 MaxSpawnCount = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Spawning", meta = (EditCondition = "!bOnlySpawnOnce"))
	bool bSpawnWaves = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy|Spawning", meta = (EditCondition = "bSpawnWaves"))
	float WaveInterval = 3.0f;
};
