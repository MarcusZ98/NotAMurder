// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NotAMurder/Interfaces/Speedable.h"
#include "Player_TEST.generated.h"

UCLASS()
class NOTAMURDER_API APlayer_TEST : public AActor, public ISpeedable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayer_TEST();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual float GetSpeed_Implementation() override;
	
	virtual void SetSpeed_Implementation(float NewSpeed) override;
	
	virtual void MultiplySpeed_Implementation(float Multiplier) override;

	virtual void ResetSpeed_Implementation() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Speed")
	float MovementSpeed = 100.0f;

	UPROPERTY()
	float OriginalSpeed;

};
