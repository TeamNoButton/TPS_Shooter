// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class SHOOTER_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ALobbyPlayerController();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UserUI)
		FString UserChat;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* PawnToPossess) override;

	//UFUNCTION(Server, Reliable)
	//	void ReqOnPossess(const FString& Name);
	//void ReqOnPossess_Implementation(const FString& Name);

	//UFUNCTION(NetMulticast, Reliable)
	//	void ResOnPossess();
	//void ResOnPossess_Implementation();


private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UUserWidget> WidgetTemplate;

	UPROPERTY()
		UUserWidget* WidgetInstance;
};
