// Fill out your copyright notice in the Description page of Project Settings.


#include "Ocean_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerCharacter.h"
#include "PlayerPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


void AOcean_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AOcean_PlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	PlayerCharacter = Cast<APlayerCharacter>(aPawn);
	PlayerPawn = Cast<APlayerPawn>(aPawn);
}

void AOcean_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer();

	if (InputSubsystem != nullptr && InputMapping != nullptr)
	{
		InputSubsystem->ClearAllMappings();
		InputSubsystem->AddMappingContext(InputMapping, 0);
	}
	else if (InputSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Missing Input Subsystem Referance"), *GetName());
		return;
	}

	else if (InputMapping == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Missing Input Mapping Referance"), *GetName());
		return;
	}

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	if (Input != nullptr)
	{
		Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AOcean_PlayerController::Move);
		Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AOcean_PlayerController::Look);
		Input->BindAction(IA_Elevation, ETriggerEvent::Triggered, this, &AOcean_PlayerController::Elevation);
		Input->BindAction(IA_Interact, ETriggerEvent::Triggered, this, &AOcean_PlayerController::Interact);
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("Missing Input Referance"));
	}
}

void AOcean_PlayerController::Move(const FInputActionValue& Value)
{
	if (PlayerCharacter != nullptr)
	{
		//FRotator CharacterRotation = PlayerCharacter->GetControlRotation();

		PlayerCharacter->AddMovementInput(
			PlayerCharacter->Camera->GetForwardVector(),
			Value.Get<FVector2D>().Y);

		PlayerCharacter->AddMovementInput(
			PlayerCharacter->Camera->GetRightVector(),
			Value.Get<FVector2D>().X);
	}

	if (PlayerPawn != nullptr)
	{
		PlayerPawn->FloatingPawnMovement->AddInputVector(PlayerPawn->Camera->GetForwardVector() * Value.Get<FVector2D>().Y);
		PlayerPawn->FloatingPawnMovement->AddInputVector(PlayerPawn->Camera->GetRightVector() * Value.Get<FVector2D>().X);

		/*PlayerPawn->AddMovementInput(
			PlayerCharacter->Camera->GetForwardVector(),
			Value.Get<FVector2D>().Y);

		PlayerPawn->AddMovementInput(
			PlayerCharacter->Camera->GetRightVector(),
			Value.Get<FVector2D>().X);*/
	}
	
}

void AOcean_PlayerController::Look(const FInputActionValue& Value)
{
	//if (PlayerCharacter == nullptr) return;

	AddYawInput(Value.Get<FVector2D>().X);
	AddPitchInput(-1 * Value.Get<FVector2D>().Y);

	//UE_LOG(LogTemp, Warning, TEXT("Mouse input: %s"), *Value.Get<FVector2D>().ToString());
}

void AOcean_PlayerController::Elevation(const FInputActionValue& Value)
{
	if (PlayerCharacter != nullptr)
	{
		FRotator CharacterRotation = PlayerCharacter->GetControlRotation();

		PlayerCharacter->AddMovementInput(
			PlayerCharacter->Camera->GetUpVector(),
			Value.Get<float>());
	}

	if (PlayerPawn != nullptr)
	{
		PlayerPawn->FloatingPawnMovement->AddInputVector(PlayerPawn->Camera->GetUpVector() * Value.Get<float>());
	}
}

void AOcean_PlayerController::Interact(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Interaction Button Press"));
}
