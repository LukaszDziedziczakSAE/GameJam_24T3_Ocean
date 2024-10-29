// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ocean_PlayerController.generated.h"
 
UCLASS()
class GAMEJAM_24T3_OCEAN_API AOcean_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* aPawn) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APlayerPawn* PlayerPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Look;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Elevation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Interact;

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void Elevation(const FInputActionValue& Value);

	UFUNCTION()
	void Interact(const FInputActionValue& Value);
};
