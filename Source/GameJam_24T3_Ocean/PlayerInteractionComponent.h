// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpgradeAirLevelDelegate);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEJAM_24T3_OCEAN_API UPlayerInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TraceLength;

	class APickupActor* Pickup;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GemsCollected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalGems;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int UpgradeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> UpgradeThreshholds;

	UFUNCTION(BlueprintCallable)
	void Interact();

	UFUNCTION(BlueprintPure)
	bool CanPickup();

	UFUNCTION(BlueprintPure)
	bool AllGemsCollected();

	UPROPERTY(BlueprintAssignable)
	FUpgradeAirLevelDelegate UpgradeAirLevel;
};
