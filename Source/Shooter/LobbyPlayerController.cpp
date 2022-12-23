// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterGameInstance.h"
#include "LobbyPlayerState.h"


ALobbyPlayerController::ALobbyPlayerController()
{
}
void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	this->SetInputMode(FInputModeUIOnly());
	this->bShowMouseCursor = true;
}
void ALobbyPlayerController::OnPossess(APawn* PawnToPossess)
{
	Super::OnPossess(PawnToPossess);
	
	ResOnPossess();
}

void ALobbyPlayerController::ReqOnPossess_Implementation(const FString& Name)
{
	auto ps = Cast<ALobbyPlayerState>(AController::PlayerState);

	ps->SetPlayerName(Name);
		
}

void ALobbyPlayerController::ResOnPossess_Implementation()
{
	
	auto GameInstance = Cast<UShooterGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	FString Name = GameInstance->GetPlayerName();
	ReqOnPossess(Name);
}
