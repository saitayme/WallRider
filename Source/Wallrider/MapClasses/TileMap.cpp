#include "TileMap.h"

#include "Room.h"

TileMap::TileMap() {}

TileMap::~TileMap() {}

std::vector<std::vector<ATile*>> TileMap::DuplicateMap() {
    std::vector<std::vector<ATile*>> mapCopy;
    for (const auto& row : Tiles) {
        std::vector<ATile*> rowCopy;
        for (const auto& tile : row) {
            rowCopy.push_back(tile->Clone()); 
        }
        mapCopy.push_back(rowCopy);
    }
    return mapCopy;
}

void TileMap::UpdateFields(std::vector<ATile*> tiles) {
    if (tiles.empty()) return;

    std::vector<std::vector<int>> effectPattern = {
        {0, 0, 1, 0, 0},
        {0, 1, 2, 1, 0},
        {1, 2, 3, 2, 1},
        {0, 1, 2, 1, 0},
        {0, 0, 1, 0, 0}
    };

    ATile* sourceTile = tiles[0]; // first tile is da source
    int sourceX, sourceY;
    // Assuming we have an entity variable that represents the entity on the sourceTile
    AEntity* entity = sourceTile->GetEntity(); // This line is hypothetical and depends on your implementation
    FindSourceTilePosition(entity, sourceX, sourceY);
    if (sourceX == -1 || sourceY == -1) {
        // Handle error: sourceTile not found
        return;
    }

    for (int i = 0; i < effectPattern.size(); ++i) {
        for (int j = 0; j < effectPattern[i].size(); ++j) {
            int effectValue = effectPattern[i][j];
            if (effectValue > 0) {
                int targetX = sourceX + i - 2; // Centering the pattern on the source
                int targetY = sourceY + j - 2;

                if (targetX >= 0 && targetX < Tiles.size() && targetY >= 0 && targetY < Tiles[targetX].size()) {
                    if (!IsBlockedByWall(targetX, targetY)) {
                        ATile* tile = Tiles[targetX][targetY]; // Use pointer directly
                        tile->ChangeCrums(effectValue);
                    }
                }
            }
        }
    }
}

bool TileMap::IsBlockedByWall(int x, int y) {
    ATile* tile = Tiles[x][y]; // Use pointer directly
    // Example logic to check if any border of the tile is not walkable
    for (auto const& border : tile->GetBorders()) {
        if (border.Value == EBorderType::Locked) {
            return true;
        }
    }
    return false;
}

void TileMap::LockQuadrant(unsigned int QuadrantId) {
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

unsigned int TileMap::GetShadewalkerQuadrant() {
    for (auto& quadrant : Quadrants) { // Cuz 'Quadrants' is a collection of all quadrants
        if (quadrant->CheckIfShadewalkerPresent()) {
            return quadrant->GetQuadrantId(); // Assuming a GetQuadrantId finds an ID
        }
    }
    return 0; // Return 0 if the Shadewalker is not found in any quadrant Ps: SHOULDN'T HAPPEN BRO
}

ATile* TileMap::GetEntityTile(AEntity* entity) {
    for (auto& row : Tiles) {
        for (ATile& tile : row) {
            auto it = std::find(tile.GetCurrentEntities().begin(), tile.GetCurrentEntities().end(), entity);
            if (it != tile.GetCurrentEntities().end()) {
                return &tile;
            }
        }
    }
    return nullptr;
}

void TileMap::InitializeMap() {
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
            Tiles[x][y] = NewObject<ATile>(GetTransientPackage(), NAME_None, RF_NoFlags, nullptr, false);
            Tiles[x][y]->SetRoom(NewObject<URoom>(GetTransientPackage(), NAME_None, RF_NoFlags, nullptr, false));
            // Set borders as walls or doors as needed
            // Logic to set walls and doors based on the room's position and type
            // This part of the code will be implemented according to the game's rules for room accessibility and connections
        }
    }
}

ERoomType TileMap::CharToRoomType(char c) {
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

void TileMap::FindSourceTilePosition(AEntity* entity, int& sourceX, int& sourceY) {
    for (int x = 0; x < Tiles.size(); ++x) {
        for (int y = 0; y < Tiles[x].size(); ++y) {
            if (Tiles[x][y]->HasEntity(entity)) { // Corrected member access
                sourceX = x;
                sourceY = y;
                return;
            }
        }
    }
    sourceX = -1; // Indicate not found
    sourceY = -1;
}
