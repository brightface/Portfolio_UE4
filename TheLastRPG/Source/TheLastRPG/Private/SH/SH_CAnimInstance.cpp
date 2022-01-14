// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/SH_CAnimInstance.h"
#include "SH/SH_Global.h"
#include "GameFramework/Character.h"

void USH_CAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void USH_CAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	CheckNull2(OwnerCharacter); // NULLÀÌ¸é returnÇÔ

	Speed = OwnerCharacter->GetVelocity().Size2D();
}