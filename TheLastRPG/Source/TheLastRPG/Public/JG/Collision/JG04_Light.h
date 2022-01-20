// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG04_Light.generated.h"

DECLARE_DELEGATE(FBoxLightBeginOverlap);

UCLASS()
class THELASTRPG_API AJG04_Light : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
	class UPointLightComponent* Light;

	UPROPERTY(VisibleDefaultsOnly)
	class UPointLightComponent* Light2;

public:
	// Sets default values for this actor's properties
	AJG04_Light();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnLight();
	UFUNCTION()
	void OffLight();

	UFUNCTION()
	FString OnRandomLight(FLinearColor InColor);
};
