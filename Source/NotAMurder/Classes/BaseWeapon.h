// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NotAMurder/Interfaces/Weapon_Interface.h"
#include "NotAMurder/Structs/WeaponData.h"
#include "BaseWeapon.generated.h"

UCLASS()
class NOTAMURDER_API ABaseWeapon : public AActor,  public IWeaponInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes")
	FWeaponData WeaponData;

	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void FireWeapon_Implementation(ABaseCharacter* OwnerOfWeapon, const FVector& StartLocation, const FVector& ForwardVector) override;

};
