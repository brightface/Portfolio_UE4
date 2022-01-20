// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C10_Override.generated.h"

UCLASS()
class THELASTRPG_API AYH_C10_Override : public AActor
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
	AYH_C10_Override();

protected:
	virtual void BeginPlay() override;

protected:
	//둘다 자식에서 가능하다(블프)
	//콜은 해주는데 알아서 몸체를 만드세요
	UFUNCTION(BlueprintImplementableEvent)
		void ChangeColorRed();
	//기본으로는 이렇게 지정해놧는데 필요하면 재정의 해라.
	UFUNCTION(BlueprintNativeEvent)
		void ChangeColorWhite();
	void ChangeColorWhite_Implementation(); //재정의 할때는 implement를 붙인다.


private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
