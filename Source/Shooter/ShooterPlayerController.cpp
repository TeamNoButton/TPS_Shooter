// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterGameInstance.h"
#include "ShooterPlayerState.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"

AShooterPlayerController::AShooterPlayerController()
{
	

}
void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	this->SetInputMode(FInputModeGameOnly());
}
//void AShooterPlayerController::OnPossess(APawn* PawnToPossess)
//{
//	Super::OnPossess(PawnToPossess);
//
//	ResOnPossess();
//}

//void AShooterPlayerController::ReqOnPossess_Implementation(const FString& Name)
//{
//	auto ps = Cast<AShooterPlayerState>(AController::PlayerState);
//
//	ps->SetPlayerName(Name);
//
//}
//
//void AShooterPlayerController::ResOnPossess_Implementation()
//{
//
//	auto GameInstance = Cast<UShooterGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
//	FString Name = GameInstance->GetPlayerName();
//	ReqOnPossess(Name);
//}
