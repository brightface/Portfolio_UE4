// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JG03_Spawner.generated.h"

UCLASS()
class THELASTRPG_API AJG03_Spawner : public AActor
{
	GENERATED_BODY()
	
private:
	//리플렉션 기능
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AJG02_SpawnActor> SpawnClass[3];
public:	
	// Sets default values for this actor's properties
	AJG03_Spawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class AJG02_SpawnActor* SpawnActors[3];

};
