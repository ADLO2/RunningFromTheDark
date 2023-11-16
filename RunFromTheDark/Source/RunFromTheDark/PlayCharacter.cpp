// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayCharacter.h"

// Sets default values
APlayCharacter::APlayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &APlayCharacter::MoveLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

void APlayCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayCharacter::MoveLeftRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}