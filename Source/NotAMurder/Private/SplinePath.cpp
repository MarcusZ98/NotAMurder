// Fill out your copyright notice in the Description page of Project Settings.

#include "SplinePath.h"

#include "Components/SplineMeshComponent.h"

// Sets default values
ASplinePath::ASplinePath()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and initialize the spline component
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent; // Set the spline component as the root component
}

// Called when the game starts or when spawned
void ASplinePath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASplinePath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
