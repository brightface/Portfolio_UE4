// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/Actor/SH_SpawnActor.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ASH_SpawnActor::ASH_SpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ASH_SpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
}

