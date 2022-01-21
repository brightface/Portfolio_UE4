// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Trace/JG04_Explosion.h"
#include "JG/JG_Global.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AJG04_Explosion::AJG04_Explosion()
{
	JG_Helpers::CreateComponent<UParticleSystemComponent>(this, &Particle, "Particle");

	UParticleSystem* particle;
	JG_Helpers::GetAsset<UParticleSystem>(&particle, "ParticleSystem'/Game/ParagonCountess/FX/Particles/Abilities/BladeSiphon/FX/p_Countess_BladeSiphon_HitFX.p_Countess_BladeSiphon_HitFX'");
	Particle->SetTemplate(particle);
	Particle->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AJG04_Explosion::BeginPlay()
{
	Super::BeginPlay();
	
}


void AJG04_Explosion::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Particle->ResetParticles();
	Particle->SetActive(true);
}