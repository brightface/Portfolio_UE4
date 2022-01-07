// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/Actor/C03_Spawner_YH.h"
#include "YH/Global_YH.h"

AC03_Spawner_YH::AC03_Spawner_YH()
{

}

// Called when the game starts or when spawned
void AC03_Spawner_YH::BeginPlay()
{
	Super::BeginPlay();
	for (int32 i = 0; i < 3; i++)
	{
		FTransform transform;
		FVector location = GetActorLocation();

		transform.SetLocation(FVector(location.X + i * 400, location.Y, location.Z));
		SpawnActors[i] = GetWorld()->SpawnActor<AC02_SpawnActor_YH>(SpawnClass[i], transform);
		//SpawnActors[i]->SetActorLocation(FVector(location.X + i * 400, location.Y, location.Z));
	}
}

