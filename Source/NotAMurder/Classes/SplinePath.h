// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NotAMurder/Interfaces/Speedable.h"
#include "SplinePath.generated.h"

UCLASS()
class NOTAMURDER_API ASplinePath : public AActor, public ISpeedable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplinePath();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float MovementSpeed = 100.0f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float GetSpeed_Implementation() override;

	virtual void SetSpeed_Implementation(float NewSpeed) override;

	virtual void ResetSpeed_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	float OriginalSpeed;

};
