// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CollisionQueryParams.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "PickupActor.h"

// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FCollisionQueryParams TraceParams = FCollisionQueryParams();
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = true;
	TraceParams.bTraceIntoSubComponents = true;

	//Re-initialize hit info
	FHitResult HitResult(ForceInit);

	APlayerCameraManager* PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (PlayerCameraManager->GetActorForwardVector() * TraceLength);

	//call GetWorld() from within an actor extending class
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,		//result
		Start,	//start
		End, //end
		ECC_GameTraceChannel1, //collision channel (ECC_GameTraceChannel1)
		TraceParams
	))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *HitResult.GetActor()->GetName());

		APickupActor* PickupInFront = Cast<APickupActor>(HitResult.GetActor());

		if (PickupInFront != nullptr && Pickup != PickupInFront)
		{
			Pickup = PickupInFront;
		}
	}

	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("No Hit"));

		if (Pickup != nullptr)
		{
			Pickup = nullptr;
		}
	}
}

void UPlayerInteractionComponent::Interact()
{
	if (Pickup != nullptr)
	{
		Pickup->Destroy();
		GemsCollected++;
		UE_LOG(LogTemp, Warning, TEXT("Gem Picked up!"));
	}
}

bool UPlayerInteractionComponent::CanPickup()
{	
	return Pickup != nullptr;
}

