// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG10_Override.generated.h"

UCLASS()
class THELASTRPG_API AJG10_Override : public AActor
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
	AJG10_Override();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	// 알아서 몸체 만들어라. 선언만 해놨다.
	UFUNCTION(BlueprintImplementableEvent) 
	void ChangeColorRed();

	// 우리가 기본은 만들어 놨다. 재정의 할거면 알아서 해라.
	UFUNCTION(BlueprintNativeEvent) 
	void ChangeColorWhite();
	void ChangeColorWhite_Implementation(); //C에서 자식 재정의 할 때 _Implementation붙음

private:
	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

private:
	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
