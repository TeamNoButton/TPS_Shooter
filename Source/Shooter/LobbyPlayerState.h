// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LobbyPlayerState.generated.h"

/**
 *
 */
UCLASS()
class SHOOTER_API ALobbyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	FORCEINLINE void SetUserName(FString Name) { UserName = Name; }


private:

	FString UserName;
};
