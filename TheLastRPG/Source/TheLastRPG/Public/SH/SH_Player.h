// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SH_Player.generated.h"

UCLASS()
class THELASTRPG_API ASH_Player : public ACharacter
{
	GENERATED_BODY()


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;

public:
	// Sets default values for this character's properties
	ASH_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

private:
	void OnRunning();
	void OffRunning();

	void OnRifle();

public:
	UFUNCTION(BlueprintCallable) // BP에서 콜할 수 있는 함수
		void ChangeColor(FLinearColor InColor);

private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;

private:
	class ASH_CRifle* Rifle;
};
