#pragma once
#include <vector>
#include <queue>
#include <utility>

class Pathfinding
{
public:
    Pathfinding(int rows, int cols);
    std::vector<std::pair<int, int>>GenerateField(int startX, int startY, int endX, int endY);

    std::pair<int, int> GetRandomTile();
    std::pair<int, int> GetNeighbors(const std::pair<int, int>& current, std::queue<std::pair<int, int>>& frontier);
    std::pair<int, int> GetRandomFrontier(std::queue<std::pair<int, int>>& frontier);
    bool IsValidTile(int x, int y);
    void MarkAsVisited(int x, int y);
    void ResetVisited();

private:
    int ROW, COL;
    std::vector<std::vector<bool>> wasVisited;
};