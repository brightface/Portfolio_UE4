#include "SH/Collision/SH_Explosion.h"
#include "SH/SH_Global.h"
#include "Particles/ParticleSystemComponent.h"

ASH_Explosion::ASH_Explosion()
{
	SH_CHelpers::CreateComponent<UParticleSystemComponent>(this, &Particle, "Particle");

	UParticleSystem* particle;
	SH_CHelpers::GetAsset<UParticleSystem>(&particle, "ParticleSystem'/Game/ParagonCountess/FX/Particles/Abilities/BlinkStrike/FX/p_Countess_BlinkStrikeFlash.p_Countess_BlinkStrikeFlash'");
	Particle->SetTemplate(particle); // 템플릿 부분에 할당해주자.
	Particle->bAutoActivate = false; // 바로 자동으로 실행되는거 끔.
}

void ASH_Explosion::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASH_Explosion::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	Particle->ResetParticles(); // 리셋해줘야함. 기존에 하던거 초기화됨
	Particle->SetActive(true); // 들어왔을때 실행
}
