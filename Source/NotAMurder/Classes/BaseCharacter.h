// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NotAMurder/Interfaces/Character_Interface.h"
#include "NotAMurder/Interfaces/Speedable.h"
#include "NotAMurder/Structs/CharacterData.h"
#include "BaseCharacter.generated.h"

UCLASS()
class NOTAMURDER_API ABaseCharacter : public ACharacter, public ISpeedable, public ICharacter_Interface
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* ShootStartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SecondaryWeaponLocation;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float GetOriginalSpeed_Implementation() override;
	virtual float GetCurrentSpeed_Implementation() override;
	virtual void SetCurrentSpeed_Implementation(const float NewSpeed) override;
	virtual void SetOriginalSpeed_Implementation(const float NewSpeed) override;
	virtual void MultiplySpeed_Implementation(const float Multiplier) override;
	virtual void ResetSpeed_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attributes")
	FCharacterData CharacterData;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Character Attributes")
	float OriginalMovementSpeed = 100.0f;

	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual FCharacterData GetCharacterData_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void SetCharacterData_Implementation(const FCharacterData& NewData) override;

	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual ECharacterType GetCharacterType_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void EquipWeapon();
	
};
