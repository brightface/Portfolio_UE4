#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C04_Light.generated.h"

UCLASS()
class THELASTRPG_API AYH_C04_Light : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;


	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;


	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light;

	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light2;

public:
	AYH_C04_Light();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnLight();

	UFUNCTION()
		void OffLight();

	UFUNCTION()
		FString OnRandomLight(FLinearColor InColor);
};