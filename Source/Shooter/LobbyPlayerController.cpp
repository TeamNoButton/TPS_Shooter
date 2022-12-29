// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterGameInstance.h"
#include "ShooterPlayerState.h"
#include "LobbyPlayerState.h"
#include "Blueprint/UserWidget.h"


ALobbyPlayerController::ALobbyPlayerController()
{
}
void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	this->SetInputMode(FInputModeUIOnly());
	this->bShowMouseCursor = true;



	if (WidgetTemplate)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString("Widget"));
		if (!WidgetInstance)
		{
			WidgetInstance = CreateWidget(this, WidgetTemplate, FName("LobbyWidget"));
		}

		if (!WidgetInstance->GetIsVisible())
		{
			WidgetInstance->AddToViewport();
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString("Widget false"));
	}




}
void ALobbyPlayerController::OnPossess(APawn* PawnToPossess)
{
	Super::OnPossess(PawnToPossess);

	//ResOnPossess();
}

//void ALobbyPlayerController::ReqOnPossess_Implementation(const FString& Name)
//{
//	auto Lobbyps = Cast<ALobbyPlayerState>(AController::PlayerState);
//
//	Lobbyps->SetUserName(Name);
//}
//
//void ALobbyPlayerController::ResOnPossess_Implementation()
//{
//
//	auto GameInstance = Cast<UShooterGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
//	FString Name = GameInstance->GetPlayerName();
//
//	ReqOnPossess(Name);
//}