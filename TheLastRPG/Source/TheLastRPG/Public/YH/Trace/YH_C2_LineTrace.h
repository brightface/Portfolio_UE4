#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C2_LineTrace.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTraceResults, class AActor*, InActor, FLinearColor, InColor);

UCLASS()
class THELASTRPG_API AYH_C2_LineTrace : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

public:
	AYH_C2_LineTrace();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void StartJump(class AActor* InActor, FLinearColor InColor);

protected:
	UFUNCTION(BlueprintCallable)
		void RestoreColor(class ACPlayer_YH* InPlayer);

private:
	TArray<class AYH_C01_Cylinder*> Cylinders;

public:
	//여기 해줘야한다. 언리얼 비피에 그래야 나온다.
	UPROPERTY(BlueprintAssignable)
		FTraceResults OnTraceResult;

};
