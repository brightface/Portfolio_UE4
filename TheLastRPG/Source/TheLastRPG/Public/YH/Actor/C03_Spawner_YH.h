

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Spawner_YH.generated.h"

UCLASS()
class THELASTRPG_API AC03_Spawner_YH : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	AC03_Spawner_YH();
private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_SpawnActor_YH> SpawnClass[3];
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class AC02_SpawnActor_YH* SpawnActors[3];
};
