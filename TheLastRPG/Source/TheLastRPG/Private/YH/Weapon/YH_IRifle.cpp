// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/Weapon/YH_IRifle.h"

// Sets default values
AYH_IRifle::AYH_IRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AYH_IRifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AYH_IRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

