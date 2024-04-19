#include "TileMap.h"

#include "Room.h"

TileMap::TileMap() {}

TileMap::~TileMap() {}

std::vector<std::vector<Tile>> TileMap::DuplicateMap() {
    std::vector<std::vector<Tile>> mapCopy;
    for (const auto& row : Tiles) {
        std::vector<Tile> rowCopy;
        for (const auto& tile : row) {
            rowCopy.push_back(*tile.Clone()); 
        }
        mapCopy.push_back(rowCopy);
    }
    return mapCopy;
}

void TileMap::UpdateFields(std::vector<Tile*> tiles) {
    if (tiles.empty()) return;

    std::vector<std::vector<int>> effectPattern = {
        {0, 0, 1, 0, 0},
        {0, 1, 2, 1, 0},
        {1, 2, 3, 2, 1},
        {0, 1, 2, 1, 0},
        {0, 0, 1, 0, 0}
    };

    Tile* sourceTile = tiles[0]; // first tile is da source
    int sourceX, sourceY;
    // Assuming we have an entity variable that represents the entity on the sourceTile
    Entity* entity = sourceTile->GetEntity(); // This line is hypothetical and depends on your implementation
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
                        Tiles[targetX][targetY].ChangeCrums(effectValue);
                    }
                }
            }
        }
    }
}

bool TileMap::IsBlockedByWall(int x, int y) {
    Tile tile = Tiles[x][y];
    // Example logic to check if any border of the tile is not walkable
    for (auto const& border : tile.GetBorders()) {
        if (border.second == BorderType::Locked) {
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
                Tiles[x][y].SetEdgeLocked("north", x == startX);
                Tiles[x][y].SetEdgeLocked("south", x == endX - 1);
                Tiles[x][y].SetEdgeLocked("east", y == endY - 1);
                Tiles[x][y].SetEdgeLocked("west", y == startY);
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

Tile* TileMap::GetEntityTile(Entity* entity) {
    for (auto& row : Tiles) {
        for (Tile& tile : row) {
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
            RoomType type = CharToRoomType(layout[x][y]);
            Tiles[x][y] = Tile();
            Tiles[x][y].SetRoom(new Room(type));
            // Set borders as walls or doors as needed
            // Logic to set walls and doors based on the room's position and type
            // This part of the code will be implemented according to the game's rules for room accessibility and connections
        }
    }
}

RoomType TileMap::CharToRoomType(char c) {
    switch (c) {
        case 'L': return RoomType::Laboratory;
        case 'H': return RoomType::Hallway;
        case 'C': return RoomType::Control;
        case 'P': return RoomType::Portal;
        case 'Q': return RoomType::QuantumBox;
        case 'S': return RoomType::Security;
        case 'E': return RoomType::Electrical;
        case 'U': return RoomType::Surgery;
        case 'T': return RoomType::Stim;
        case 'N': return RoomType::Nothing;
        case 'B': return RoomType::Breakroom;
        case 'K': return RoomType::Kitchen;
        case 'R': return RoomType::Crematorium;
        case 'A': return RoomType::Armory;
        default: return RoomType::Nothing;
    }
}

void TileMap::FindSourceTilePosition(Entity* entity, int& sourceX, int& sourceY) {
    for (int x = 0; x < Tiles.size(); ++x) {
        for (int y = 0; y < Tiles[x].size(); ++y) {
            if (Tiles[x][y].HasEntity(entity)) { // Corrected member access
                sourceX = x;
                sourceY = y;
                return;
            }
        }
    }
    sourceX = -1; // Indicate not found
    sourceY = -1;
}
