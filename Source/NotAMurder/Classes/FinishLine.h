// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FinishLine.generated.h"

UCLASS()
class NOTAMURDER_API AFinishLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFinishLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* CollisionBox;	

};
