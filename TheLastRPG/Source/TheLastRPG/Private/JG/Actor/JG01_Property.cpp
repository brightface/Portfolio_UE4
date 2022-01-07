// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Actor/JG01_Property.h"

// Sets default values
AJG01_Property::AJG01_Property()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	C = 5;
}

// Called when the game starts or when spawned
void AJG01_Property::BeginPlay()
{
	Super::BeginPlay();
	
	//FString str;
	//str.Append("A : ");
	//str.Append(FString::FromInt(A));
	//str.Append(", B : ");
	//str.Append(FString::FromInt(B));	
	//str.Append(", C : ");
	//str.Append(FString::FromInt(C));

	//GLog->Log(str);
}

// Called every frame
void AJG01_Property::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

