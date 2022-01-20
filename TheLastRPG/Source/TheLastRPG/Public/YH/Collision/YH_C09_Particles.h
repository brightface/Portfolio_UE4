// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C09_Particles.generated.h"

UCLASS()
class THELASTRPG_API AYH_C09_Particles : public AActor
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
	AYH_C09_Particles();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void PlayParticle(int32 InIndex);


};
