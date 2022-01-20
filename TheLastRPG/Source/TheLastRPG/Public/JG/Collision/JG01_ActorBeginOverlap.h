// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG01_ActorBeginOverlap.generated.h"

UCLASS()
class THELASTRPG_API AJG01_ActorBeginOverlap : public AActor
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
	AJG01_ActorBeginOverlap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// 델리게이션은 반드시 UFUNCTION사용
	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
