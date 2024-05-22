#include "TileMap.h"
#include "Room.h"

UTileMap::UTileMap() {}

UTileMap::~UTileMap() {}

TArray<TArray<ATile>> UTileMap::DuplicateMap() {
    TArray<TArray<ATile>> mapCopy;
    for (const auto& row : Tiles) {
        TArray<ATile> rowCopy;
        for (const auto& tile : row) {
            rowCopy.Add(*tile.Clone()); 
        }
        mapCopy.Add(rowCopy);
    }
    return mapCopy;
}

void UTileMap::UpdateFields(TArray<ATile*> tiles) {
    if (tiles.IsEmpty()) return;

    TArray<TArray<int>> effectPattern = {
        {0, 0, 1, 0, 0},
        {0, 1, 2, 1, 0},
        {1, 2, 3, 2, 1},
        {0, 1, 2, 1, 0},
        {0, 0, 1, 0, 0}
    };

    ATile* sourceTile = tiles[0]; // first tile is the source
    int sourceX, sourceY;
    AEntity* entity = sourceTile->GetEntity(); // This line is hypothetical and depends on your implementation
    FindSourceTilePosition(entity, sourceX, sourceY);
    if (sourceX == -1 || sourceY == -1) {
        // Handle error: sourceTile not found
        return;
    }

    for (int i = 0; i < effectPattern.Num(); ++i) {
        for (int j = 0; j < effectPattern[i].Num(); ++j) {
            int effectValue = effectPattern[i][j];
            if (effectValue > 0) {
                int targetX = sourceX + i - 2; // Centering the pattern on the source
                int targetY = sourceY + j - 2;

                if (targetX >= 0 && targetX < Tiles.Num() && targetY >= 0 && targetY < Tiles[targetX].Num()) {
                    if (!IsBlockedByWall(targetX, targetY)) {
                        Tiles[targetX][targetY]->ChangeCrums(effectValue);
                    }
                }
            }
        }
    }
}

bool UTileMap::IsBlockedByWall(int x, int y) {
    ATile* tile = Tiles[x][y];
    // Example logic to check if any border of the tile is not walkable
    for (auto const& border : tile->GetBorders()) {
        if (border.Value == BorderType::Locked) {
            return true;
        }
    }
    return false;
}

void UTileMap::LockQuadrant(unsigned int QuadrantId) {
    int startX, startY, endX, endY;
    switch (QuadrantId) {
        case 1: startX = 0; startY = 0; endX = 4; endY = 4; break;
        case 2: startX = 5; startY = 0; endX = 9; endY = 4; break;
        case 3: startX = 0; startY = 5; endX = 4; endY = 9; break;
        case 4: startX = 5; startY = 5; endX = 9; endY = 9; break;
        default: return; // Invalid quadrant ID
    }

    for (int x = startX; x < endX; ++x) {
        for (int y = startY; y < endY; ++y) {
            if (x == startX || x == endX - 1 || y == startY || y == endY - 1) {
                Tiles[x][y]->SetEdgeLocked("north", x == startX);
                Tiles[x][y]->SetEdgeLocked("south", x == endX - 1);
                Tiles[x][y]->SetEdgeLocked("east", y == endY - 1);
                Tiles[x][y]->SetEdgeLocked("west", y == startY);
            }
        }
    }
}

unsigned int UTileMap::GetShadewalkerQuadrant() {
    for (auto& quadrant : Quadrants) {
        if (quadrant->CheckIfShadewalkerPresent()) {
            return quadrant->GetQuadrantId();
        }
    }
    return 0; // Return 0 if the Shadewalker is not found in any quadrant
}

ATile* UTileMap::GetEntityTile(AEntity* entity) {
    for (auto& row : Tiles) {
        for (ATile& tile : row) {
            if (tile.HasEntity(entity)) {
                return &tile;
            }
        }
    }
    return nullptr;
}

void UTileMap::InitializeMap() {
    char layout[9][9] = {
        {'L', 'L', 'L', 'L', 'H', 'C', 'C', 'C', 'C'},
        {'P', 'L', 'L', 'Q', 'H', 'C', 'C', 'S', 'S'},
        {'P', 'P', 'Q', 'Q', 'H', 'S', 'S', 'S', 'S'},
        {'P', 'P', 'Q', 'Q', 'H', 'E', 'E', 'E', 'E'},
        {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
        {'U', 'U', 'T', 'T', 'H', 'N', 'B', 'K', 'K'},
        {'U', 'U', 'T', 'T', 'H', 'N', 'B', 'K', 'K'},
        {'R', 'R', 'R', 'T', 'H', 'N', 'B', 'K', 'A'},
        {'R', 'R', 'R', 'T', 'H', 'N', 'B', 'A', 'A'}
    };

    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            ERoomType type = CharToRoomType(layout[x][y]);
            Tiles[x][y] = NewObject<ATile>();
            Tiles[x][y]->SetRoom(NewObject<URoom>(type));
            // Set borders as walls or doors as needed
            // Logic to set walls and doors based on the room's position and type
            // This part of the code will be implemented according to the game's rules for room accessibility and connections
        }
    }
}

ERoomType UTileMap::CharToRoomType(char c) {
    switch (c) {
        case 'L': return ERoomType::Laboratory;
        case 'H': return ERoomType::Hallway;
        case 'C': return ERoomType::Control;
        case 'P': return ERoomType::Portal;
        case 'Q': return ERoomType::QuantumBox;
        case 'S': return ERoomType::Security;
        case 'E': return ERoomType::Electrical;
        case 'U': return ERoomType::Surgery;
        case 'T': return ERoomType::Stim;
        case 'N': return ERoomType::Nothing;
        case 'B': return ERoomType::Breakroom;
        case 'K': return ERoomType::Kitchen;
        case 'R': return ERoomType::Crematorium;
        case 'A': return ERoomType::Armory;
        default: return ERoomType::Nothing;
    }
}

void UTileMap::FindSourceTilePosition(AEntity* entity, int& sourceX, int& sourceY) {
    for (int x = 0; x < Tiles.Num(); ++x) {
        for (int y = 0; y < Tiles[x].Num(); ++y) {
            if (Tiles[x][y]->HasEntity(entity)) {
                sourceX = x;
                sourceY = y;
                return;
            }
        }
    }
    sourceX = -1; // Indicate not found
    sourceY = -1;
}
