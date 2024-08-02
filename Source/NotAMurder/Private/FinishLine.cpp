// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"

// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();

	// Create the collision box component
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("AreaTrigger"));
	
	// Set the default size of the collision box (optional)
	CollisionBox->InitBoxExtent(FVector(50.f, 50.f, 50.f));
    
	// Enable the collision box to be visible in the editor and game
	CollisionBox->SetCollisionProfileName(TEXT("OverlapAll"));

	// Make the collision box the root component
	CollisionBox->SetupAttachment(RootComponent);
	
}

// Called every frame
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

