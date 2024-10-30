// Fill out your copyright notice in the Description page of Project Settings.


#include "Ocean_GameMode.h"
#include "Ocean_HUD.h"
#include "Kismet/GameplayStatics.h"

void AOcean_GameMode::EndGame_Implementation()
{
	AOcean_HUD* HUD = Cast<AOcean_HUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	HUD->ShowEndScreen();


}

void AOcean_GameMode::BeginPlay()
{
	Super::BeginPlay();

	PlayAmbientSound();
}

void AOcean_GameMode::PlayAmbientSound()
{
	if (AmbientSounds == nullptr) return;

	float t = AmbientSounds->GetDuration();
	UGameplayStatics::PlaySound2D(GetWorld(), AmbientSounds);
	FTimerHandle AttackTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &AOcean_GameMode::PlayAmbientSound, t, false);
}
