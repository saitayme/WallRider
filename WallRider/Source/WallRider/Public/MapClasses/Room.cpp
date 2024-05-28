#include "Room.h"
#include "../Entity/Entity.h"

URoom::URoom(ERoomType Type) : Type(Type) {}

URoom::~URoom() {}

void URoom::Use(AEntity* Entity, const FString& Instruction) {
    if (ActOnUse.IsBound()) {
        ActOnUse.Execute(Entity, Instruction);
    }
}

void URoom::AddEntity(AEntity* Entity) {
    Entities.Add(Entity);
}

void URoom::RemoveEntity(AEntity* Entity) {
    Entities.RemoveSingle(Entity);
}

void URoom::TriggerSabotage() {
    // Implementation depends on how sabotage affects the room or game state
}

void URoom::SetRoomType(ERoomType Type) {
    this->Type = Type;
}
}