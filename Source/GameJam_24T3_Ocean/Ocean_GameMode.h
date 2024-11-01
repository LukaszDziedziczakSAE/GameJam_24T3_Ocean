// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ocean_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_24T3_OCEAN_API AOcean_GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void PlayAmbientSound();

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EndGame();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* AmbientSounds;
};
