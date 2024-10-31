// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class GAMEJAM_24T3_OCEAN_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPlayerInteractionComponent* PlayerInteractionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector MovementInput;

	UFUNCTION(BlueprintCallable)
	void AddMovement(FVector Movement);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementDampening{ 0.05f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAudioComponent* AudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* BreathingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* ChockingSound;
};
