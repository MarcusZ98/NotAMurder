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
	ECharacterType CharacterType = ECharacterType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (ToolTip = "Enable this to override the speed of the character"))
	bool bOverrideCharacterData = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "bOverrideCharacterData"))
	FCharacterData OverridenCharacterData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Player",
		meta = (EditCondition = "CharacterType == ECharacterType::Player"),
		meta = (ToolTip = "Add the player character class here"))
	AActor* PlayerParent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Custom|Player",
		meta = (EditCondition = "CharacterType == ECharacterType::Player"))
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy"),
		meta = (ToolTip = "Add the enemy character class here"))
	TSubclassOf<AEnemyCharacter> EnemyClass = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Custom|Enemy",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	AActor* EnemyParent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	int32 GroupSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy"),
		meta = (ToolTip = "Adjust the distance between enemies in the group"))
	float DistanceBetweenEnemies = 150;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy"),
		meta = (ToolTip = "Overrides the enemy data set in the enemy class"))
	bool bOverrideEnemyData = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy",
		meta = (EditCondition = "bOverrideEnemyData"))
	FEnemyData OverriddenEnemyData;
	
};
