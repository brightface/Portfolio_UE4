// Fill out your copyright notice in the Description page of Project Settings.

#include "YH/YH_CAnimInstance.h"
#include "YH/Global_YH.h"
#include "GameFramework/Character.h"

void UYH_CAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void UYH_CAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	CheckNull(OwnerCharacter);
	//게임프레임워크에 있다.
	Speed = OwnerCharacter->GetVelocity().Size2D();
	//벡터랭쓰이다.
}
