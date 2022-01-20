// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG07_SpotLight.generated.h"

UCLASS()
class THELASTRPG_API AJG07_SpotLight : public AActor
{
	GENERATED_BODY()
	
	private:
	UPROPERTY(VisibleDefaultsOnly)
	class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
	class USpotLightComponent* SpotLights[3];

public:	
	// Sets default values for this actor's properties
	AJG07_SpotLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnLightColor(int32 InIndex, FLinearColor InColor);

};
