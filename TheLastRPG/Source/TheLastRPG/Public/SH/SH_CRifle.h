// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SH_CRifle.generated.h"

UCLASS()
class THELASTRPG_API ASH_CRifle : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		FName HandSocket = "Hand_Rifle";

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		FName HolsterSocket = "Holster_Rifle";

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UAnimMontage* GrabMontage;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UAnimMontage* UngrabMontage;

public:
	// 자기 자료형을 생성해서 리턴함. static이라 독립적임. 월드와 캐릭터를 받아준다.
	static ASH_CRifle* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

public:
	FORCEINLINE bool GetEquipped() { return bEquipped; }

public:	
	ASH_CRifle();

	void Equip();
	void Begin_Equip();
	void End_Equip();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	class ACharacter* OwnerCharacter;

	bool bEquipped;
};
