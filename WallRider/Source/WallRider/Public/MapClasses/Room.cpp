#include "Room.h"
#include "../Entity/Entity.h"

void URoom::Use(AEntity* Entity, const FString& Instruction) {
    // Implementation depends on the instruction and entity interaction
    // Assuming ActOnUse is a delegate or similar callable
    if (ActOnUse.IsBound()) {
        ActOnUse.Execute(Entity, Instruction);
    }
}

void URoom::AddEntity(AEntity* Entity) {
    Entities.Add(Entity);
}

void URoom::RemoveEntity(AEntity* Entity) {
    Entities.Remove(Entity);
}

void URoom::TriggerSabotage() {
    // Implementation depends on how sabotage affects the room or game state
}
}