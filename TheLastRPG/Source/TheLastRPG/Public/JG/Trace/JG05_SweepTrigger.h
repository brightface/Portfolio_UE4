// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG05_SweepTrigger.generated.h"

UCLASS()
class THELASTRPG_API AJG05_SweepTrigger : public AActor
{
	GENERATED_BODY()
	
	
	private:
	UPROPERTY(VisibleDefaultsOnly)
	class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
	class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Text;
public:	
	// Sets default values for this actor's properties
	AJG05_SweepTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
