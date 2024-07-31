// Fill out your copyright notice in the Description page of Project Settings.

#include "SplinePath.h"

// Sets default values
ASplinePath::ASplinePath()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and initialize the spline component
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent; // Set the spline component as the root component

	/*TotalSplineLength = SplineComponent->GetSplineLength();

	switch (CharacterType)
	{
		case ECharacterType::None:
			break;
		case ECharacterType::Player:
			SetUpPlayerCharacter();
			break;
		case ECharacterType::Enemy:
			break;
	} */
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

void ASplinePath::SetUpPlayerCharacter()
{
	PlayerParent->SetActorTransform(SplineComponent->GetTransformAtSplinePoint(SpawnIndex, ESplineCoordinateSpace::World));
}

void ASplinePath::SetUpEnemyCharacters()
{
	const int32 Columns = UE4::SSE::CeilToInt32(sqrt(GroupSize));
	int32 Rows = UE4::SSE::CeilToInt32(static_cast<float>(GroupSize) / Columns);
	float Offset = ((Columns-1) * DistanceBetweenEnemies) / 2;
	
	EnemySpawningPositions.Empty();

	if(GroupSize <= 0) return;

	if(GroupSize == SavedEnemyPositions.Num())
	{
		for(auto Position : SavedEnemyPositions)
		{
			UStaticMeshComponent* Sphere = NewObject<UStaticMeshComponent>(this);
		}
	}
	
}

void ASplinePath::SavePositions()
{
	SavedEnemyPositions.Empty();
	
	for(UStaticMeshComponent* Sphere : EnemySpawningPositions)
	{
		SavedEnemyPositions.Add(Sphere->GetRelativeLocation());
	}
}

void ASplinePath::LoadPositions()
{
	if(SavedEnemyPositions.Num() == 0 || SavedEnemyPositions.Num() != GroupSize) return;

	for(int i = 0; i < EnemySpawningPositions.Num(); i++)
	{
		EnemySpawningPositions[i]->SetRelativeLocation(SavedEnemyPositions[i]);
	}
}

