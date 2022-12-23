// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletHitInterface.h"
#include "Explosive.generated.h"

UCLASS()
class SHOOTER_API AExplosive : public AActor, public IBulletHitInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void ReqDestroy(FHitResult HitResult, AActor* Shooter, AController* ShooterController);

	UFUNCTION(NetMulticast, Reliable)
	void ResDestroy(FHitResult HitResult, AActor* Shooter, AController* ShooterController);

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

private:

	/** Explosion when hit by a bullet */
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* ExplodeParticles;

	/** Sound to play when hit by bullets */
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class USoundCue* ImpactSound;

	/** Mesh for the explosive */
	UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ExplosiveMesh;

	/** Used to determine what Actors overlap during explosion */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* OverlapSphere;

	/** Damage amount for explosive */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	float Damage;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BulletHit_Implementation(FHitResult HitResult, AActor* Shooter, AController* ShooterController) override;

	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return ExplosiveMesh; }

};
