// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG04_Explosion.generated.h"

UCLASS()
class THELASTRPG_API AJG04_Explosion : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
	class UParticleSystemComponent* Particle;

public:	
	// Sets default values for this actor's properties
	AJG04_Explosion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
