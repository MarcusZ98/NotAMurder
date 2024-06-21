// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "EnemyCharacter.h"
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
	AActor* AttachedActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy", meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	AEnemyCharacter* AttachedEnemy = nullptr;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Enemy", meta = (EditCondition = "CharacterType == ECharacterType::Enemy"))
	
};
