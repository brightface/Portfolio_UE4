// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SH_Light.generated.h"

UCLASS()
class THELASTRPG_API ASH_Light : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light;

public:	
	ASH_Light();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnLight();
	UFUNCTION()
		void OffLight();
};
