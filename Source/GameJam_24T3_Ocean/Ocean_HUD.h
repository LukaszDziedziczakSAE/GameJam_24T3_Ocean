// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Ocean_HUD.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_24T3_OCEAN_API AOcean_HUD : public AHUD
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowStartScreen();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowGameHUD();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowEndScreen();

	
};
