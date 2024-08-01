// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SplinePath.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "StartSplineTrigger.generated.h"

UCLASS()
class NOTAMURDER_API AStartSplineTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStartSplineTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Custom")
	TArray<ASplinePath*> SplinePathsToStart;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* CollisionBox;
};
