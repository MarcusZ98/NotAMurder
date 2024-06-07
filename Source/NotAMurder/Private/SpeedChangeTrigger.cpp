// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedChangeTrigger.h"

#include "NotAMurder/Interfaces/Speedable.h"

// Sets default values
ASpeedChangeTrigger::ASpeedChangeTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the collision box component
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("AreaTrigger"));
	
	// Set the default size of the collision box (optional)
	CollisionBox->InitBoxExtent(FVector(50.f, 50.f, 50.f));
    
	// Enable the collision box to be visible in the editor and game
	CollisionBox->SetCollisionProfileName(TEXT("OverlapAll"));

	// Attach the collision box to the root component
	CollisionBox->SetupAttachment(RootComponent);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASpeedChangeTrigger::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ASpeedChangeTrigger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpeedChangeTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpeedChangeTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if(OtherActor->GetClass()->ImplementsInterface(USpeedable::StaticClass()))
	{
		ISpeedable::Execute_MultiplySpeed(OtherActor, 5);
	}
}

