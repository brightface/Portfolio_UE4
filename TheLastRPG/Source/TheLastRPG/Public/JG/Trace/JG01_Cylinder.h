// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG01_Cylinder.generated.h"

UCLASS()
class THELASTRPG_API AJG01_Cylinder : public AActor
{
	GENERATED_BODY()
	
	private:
	UPROPERTY(VisibleDefaultsOnly)
	class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
	class UStaticMeshComponent* Mesh;

public:	
	// Sets default values for this actor's properties
	AJG01_Cylinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
