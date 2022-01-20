// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG02_LineTrace.generated.h"

// 첫번째 인자(타입)이 겹치면 안됨. 특이하게 FTraceResult_JG는 되는데 JG_FTraceResult는 안됨
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTraceResult_JG, class AActor*, InActor, FLinearColor, InColor);

UCLASS()
class THELASTRPG_API AJG02_LineTrace : public AActor
{
	GENERATED_BODY()
	
	private:
	UPROPERTY(VisibleDefaultsOnly)
	class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
	class UTextRenderComponent* Text;
	
public:	
	// Sets default values for this actor's properties
	AJG02_LineTrace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void StartJump(class AActor* InActor, FLinearColor InColor);

protected:
	UFUNCTION(BlueprintCallable)
	void RestoreColor(class AJG_Player* InPlayer);

private:
	TArray<class AJG01_Cylinder*> Cylinders;

public:
	UPROPERTY(BlueprintAssignable) 
	FTraceResult_JG JG_OnTraceResult;
};
