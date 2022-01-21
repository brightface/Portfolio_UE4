// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C01_Cylinder.generated.h"

UCLASS()
class THELASTRPG_API AYH_C01_Cylinder : public AActor
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
	AYH_C01_Cylinder();

protected:
	virtual void BeginPlay() override;

};
