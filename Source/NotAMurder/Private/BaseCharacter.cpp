// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter(): OriginalMovementSpeed(MovementSpeed)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseCharacter::GetOriginalSpeed_Implementation()
{
	return OriginalMovementSpeed;
}

float ABaseCharacter::GetCurrentSpeed_Implementation()
{
	return MovementSpeed;
}

void ABaseCharacter::SetSpeed_Implementation(float NewSpeed)
{
	MovementSpeed = NewSpeed;
}

void ABaseCharacter::MultiplySpeed_Implementation(float Multiplier)
{
	MovementSpeed *= Multiplier;
}

void ABaseCharacter::ResetSpeed_Implementation()
{
	MovementSpeed = OriginalMovementSpeed;
}

