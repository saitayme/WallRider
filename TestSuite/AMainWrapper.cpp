#include "AMainWrapper.h"
#include "../Action/Move.h"
#include "../Entity/Player.h"

// Sets default values
AMainWrapper::AMainWrapper()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainWrapper::BeginPlay()
{
	Super::BeginPlay();
	
	Player p;
	p.Use("Players related Entity", "Players related Instruction");
	Action::Move m;
	m.Act("Move related Instruction");
}