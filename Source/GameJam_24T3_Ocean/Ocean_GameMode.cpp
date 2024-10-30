// Fill out your copyright notice in the Description page of Project Settings.


#include "Ocean_GameMode.h"
#include "Ocean_HUD.h"

void AOcean_GameMode::EndGame_Implementation()
{
	AOcean_HUD* HUD = Cast<AOcean_HUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	HUD->ShowEndScreen();


}
