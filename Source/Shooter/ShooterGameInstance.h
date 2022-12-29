#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ShooterGameInstance.generated.h"


USTRUCT(BlueprintType)
struct FUserScore
{
	GENERATED_BODY()


		UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 UserKill;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 UserDeath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString UserName;



};

UCLASS()
class SHOOTER_API UShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		void SetPlayerName(FString Name);

private:



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameInstance, meta = (AllowPrivateAccess = "true"))
		FString PlayerName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GameInstance, meta = (AllowPrivateAccess = "true"))
		FUserScore UserKillDeath;

public:

	FORCEINLINE FString GetPlayerName() { return PlayerName; }

};
