// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C01_ActorBeginOverlap.generated.h"

UCLASS()
class THELASTRPG_API AYH_C01_ActorBeginOverlap : public AActor
{
	GENERATED_BODY()
	
private:
	//애를 부모로 놓겠다.
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	//충돌체 정의
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;
	//텍스트랜더링할애
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
public:	

	AYH_C01_ActorBeginOverlap();

protected:

	virtual void BeginPlay() override;
private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);


};
