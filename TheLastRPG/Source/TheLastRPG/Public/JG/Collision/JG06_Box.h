// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG06_Box.generated.h"

UCLASS()
class THELASTRPG_API AJG06_Box : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh[3];


public:
	// Sets default values for this actor's properties
	AJG06_Box();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnPhysics(int32 InIndex, FLinearColor InColor);

private:
	UMaterialInstanceDynamic* Materials[3];
	FVector WorldLocation[3];

};
