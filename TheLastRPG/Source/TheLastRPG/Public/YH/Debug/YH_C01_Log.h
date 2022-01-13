#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C01_Log.generated.h"

UCLASS()
class THELASTRPG_API AYH_C01_Log : public AActor
{
	GENERATED_BODY()
	
public:	
	AYH_C01_Log();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	float Time;
};
