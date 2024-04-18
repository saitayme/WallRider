#include "TileMap.h"

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
    int sourceX, sourceY; // These are determined based on the sourceTile's position in the Tiles array

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
    for (auto const& border : tile.Borders) {
        if (border.second == BorderType::NotWalkThrough || border.second == BorderType::Locked) {
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
    for (auto& quadrant : Quadrants) { // Assuming 'Quadrants' is a collection of all quadrants
        if (quadrant->CheckIfShadewalkerPresent()) {
            return quadrant->GetQuadrantId(); // Assuming a GetQuadrantId finds an ID
        }
    }
    return 0; // Return 0 if the Shadewalker is not found in any quadrant
}

Tile* TileMap::GetEntityTile(Entity* entity) {
    for (auto& row : Tiles) {
        for (Tile& tile : row) {
            auto it = std::find(tile.CurrentEntities.begin(), tile.CurrentEntities.end(), entity);
            if (it != tile.CurrentEntities.end()) {
                return &tile;
            }
        }
    }
    return nullptr;
}