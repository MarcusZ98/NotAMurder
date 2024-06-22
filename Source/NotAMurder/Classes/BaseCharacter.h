// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NotAMurder/Enums/CharacterType.h"
#include "NotAMurder/Interfaces/Speedable.h"
#include "BaseCharacter.generated.h"

UCLASS()
class NOTAMURDER_API ABaseCharacter : public ACharacter, public ISpeedable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float GetOriginalSpeed_Implementation() override;
	virtual float GetCurrentSpeed_Implementation() override;
	virtual void SetSpeed_Implementation(float NewSpeed) override;
	virtual void MultiplySpeed_Implementation(float Multiplier) override;
	virtual void ResetSpeed_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	float MovementSpeed = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom")
	ECharacterType CharacterType = ECharacterType::Default;

private:
	
    UPROPERTY(BlueprintReadWrite, Category = "Custom", meta = (AllowPrivateAccess = "true"))
	float OriginalMovementSpeed;

};
