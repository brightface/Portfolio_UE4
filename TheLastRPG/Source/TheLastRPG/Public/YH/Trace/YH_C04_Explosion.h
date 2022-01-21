#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YH_C04_Explosion.generated.h"

UCLASS()
class THELASTRPG_API AYH_C04_Explosion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AYH_C04_Explosion();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystemComponent* Particle;


protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};

