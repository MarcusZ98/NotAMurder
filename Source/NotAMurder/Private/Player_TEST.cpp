// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_TEST.h"

// Sets default values
APlayer_TEST::APlayer_TEST()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OriginalSpeed = MovementSpeed;
}

// Called when the game starts or when spawned
void APlayer_TEST::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_TEST::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float APlayer_TEST::GetSpeed_Implementation()
{
	return MovementSpeed;
}

void APlayer_TEST::SetSpeed_Implementation(float NewSpeed)
{
	MovementSpeed = NewSpeed;
}

void APlayer_TEST::MultiplySpeed_Implementation(float Multiplier)
{
	MovementSpeed *= Multiplier;
}

void APlayer_TEST::ResetSpeed_Implementation()
{
	MovementSpeed = OriginalSpeed;
}

