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

private:
	UFUNCTION()
	void SetUpPlayerCharacter();

	UFUNCTION()
	void SetUpEnemyCharacters();
	
	//Blueprint properties
public:
	
	UPROPERTY(BlueprintReadWrite, Category = "Custom")
	float CurrentDistanceAlongSpline = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Custom")
	float TotalSplineLength = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Custom")
	TArray<UStaticMeshComponent*> EnemySpawningPositions;

	UPROPERTY(BlueprintReadWrite, Category = "Custom")
	TArray<AEnemyCharacter*> EnemyCharacters;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	ASplinePath();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Custom properties
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline")
	USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	ECharacterType CharacterType = ECharacterType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (ToolTip = "Enable this to override the speed of the character"))
	bool bOverrideCharacterData = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "bOverrideCharacterData", EditConditionHides))
	FCharacterData OverridenCharacterData;

	// Player properties
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Player", EditConditionHides, ToolTip = "Add the player character class here"))
	AActor* PlayerParent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Custom",
	meta = (EditCondition = "CharacterType == ECharacterType::Player", EditConditionHides))
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Custom",
	meta = (EditCondition = "CharacterType == ECharacterType::Player", EditConditionHides, ClampMin = 0))
	int32 SpawnIndex = 0; 

	// Enemy properties

	UFUNCTION(CallInEditor, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides))
	void SavePositions();
	
	UFUNCTION(CallInEditor, Category = "Custom",
	meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides))
	void LoadPositions();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Custom", meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides))
	TArray<FVector> SavedEnemyPositions = TArray<FVector>();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides))
	TSubclassOf<AEnemyCharacter> EnemyClass = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides))
	AActor* EnemyParent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides, ClampMin = 1))
	int32 GroupSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides, ClampMin = 1))
	float DistanceBetweenEnemies = 150;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "CharacterType == ECharacterType::Enemy", EditConditionHides))
	bool bOverrideEnemyData = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom",
		meta = (EditCondition = "bOverrideEnemyData", EditConditionHides))
	FEnemyData OverriddenEnemyData;
	
};
