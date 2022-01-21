#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C03_Trigger.generated.h"

DECLARE_DELEGATE(FBoxLightBeginOverlap); //void __(void)
DECLARE_DELEGATE(FBoxLightEndOverlap); //void __(void)
DECLARE_DELEGATE_RetVal_OneParam(FString, FBoxLightRandomBeginOverlap, FLinearColor);


UCLASS()
class THELASTRPG_API AYH_C03_Trigger : public AActor
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
	AYH_C03_Trigger();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FBoxLightBeginOverlap OnBoxLightBeginOverlap;
	FBoxLightEndOverlap OnBoxLightEndOverlap;
	FBoxLightRandomBeginOverlap OnBoxLightRandomBeginOverlap;

};