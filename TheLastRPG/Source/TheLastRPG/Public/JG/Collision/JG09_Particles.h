// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG09_Particles.generated.h"

UCLASS()
class THELASTRPG_API AJG09_Particles : public AActor
{
	GENERATED_BODY()
	
	private:
	UPROPERTY(VisibleDefaultsOnly)
	class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
	class UParticleSystem* Particles[3];

public:	
	// Sets default values for this actor's properties
	AJG09_Particles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void PlayParticle(int32 InIndex);
};
