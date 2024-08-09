// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseWeapon.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CharacterData.CharacterType = ECharacterType::None;

	ShootStartLocation = CreateDefaultSubobject<USceneComponent>(TEXT("ShootStartLocation"));
	ShootStartLocation->SetupAttachment(RootComponent);

	SecondaryWeaponLocation = CreateDefaultSubobject<USceneComponent>(TEXT("SecondaryWeaponLocation"));
	SecondaryWeaponLocation->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	OriginalMovementSpeed = CharacterData.MovementSpeed;
	EquipWeapon();

	CharacterData.CurrentHealth = CharacterData.MaxHealth;
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
	return CharacterData.MovementSpeed;
}

void ABaseCharacter::SetCurrentSpeed_Implementation(const float NewSpeed)
{
	CharacterData.MovementSpeed = NewSpeed;
}

void ABaseCharacter::SetOriginalSpeed_Implementation(const float NewSpeed)
{
	OriginalMovementSpeed = NewSpeed;
	CharacterData.MovementSpeed = OriginalMovementSpeed;
}

void ABaseCharacter::MultiplySpeed_Implementation(const float Multiplier)
{
	CharacterData.MovementSpeed *= Multiplier;
}

void ABaseCharacter::ResetSpeed_Implementation()
{
	CharacterData.MovementSpeed = OriginalMovementSpeed;
}

FCharacterData ABaseCharacter::GetCharacterData_Implementation()
{
	return CharacterData;
}

void ABaseCharacter::SetCharacterData_Implementation(const FCharacterData& NewData)
{
	CharacterData = NewData;
	OriginalMovementSpeed = CharacterData.MovementSpeed;
}

ECharacterType ABaseCharacter::GetCharacterType_Implementation()
{
	return CharacterData.CharacterType;
}

void ABaseCharacter::EquipWeapon()
{
	if (CharacterData.Weapon)
	{
		CharacterData.WeaponInstance = GetWorld()->SpawnActor<ABaseWeapon>(CharacterData.Weapon, GetActorLocation(), GetActorRotation());
		CharacterData.WeaponInstance->AttachToComponent(ShootStartLocation, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
	if(CharacterData.SecondaryWeapon)
	{
		CharacterData.SecondaryWeaponInstance = GetWorld()->SpawnActor<ABaseWeapon>(CharacterData.SecondaryWeapon, GetActorLocation(),GetActorRotation());
		CharacterData.SecondaryWeaponInstance->AttachToComponent(SecondaryWeaponLocation,FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

