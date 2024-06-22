// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "NotAMurder/Enums/CharacterType.h"
#include "SpeedChangeTrigger.generated.h"

UCLASS()
class NOTAMURDER_API ASpeedChangeTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeedChangeTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	TArray<ECharacterType> CharacterTypesToEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	bool bUsePercentageMovement = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom", meta = (EditCondition = "!bUsePercentageMovement"))
	float NewMovementSpeed = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom", meta = (EditCondition = "bUsePercentageMovement"))
	float PercentageMovement = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	bool bUseSmoothTransition = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom", meta = (EditCondition = "bUseSmoothTransition"))
	float TransitionDuration = 1.0f;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* CollisionBox;

};
