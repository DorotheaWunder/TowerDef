#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <map>

class Pathfinding
{
public:
    Pathfinding(int rows, int cols);
    std::vector<std::pair<int, int>>GenerateField(int startX, int startY, int endX, int endY);

    std::pair<int, int> GetRandomTile();
    std::pair<int, int> GetRandomFrontier(std::queue<std::pair<int, int>>& frontier);

    std::pair<int, int> GetNeighbors(const std::pair<int, int>& current,std::queue<std::pair<int, int>>& frontier,
    std::map<std::pair<int, int>, std::pair<int, int> >& cameFrom);
    std::vector<std::pair<int,int>> TrackPath(const std::map<std::pair<int, int>, std::pair<int, int>>& cameFrom,
    const std::pair<int, int>& start, const std::pair<int, int>& goal);

    bool IsValidTile(int x, int y);
    void MarkAsVisited(int x, int y);
    void ResetVisited();

private:
    int ROW, COL;
    std::vector<std::vector<bool>> wasVisited;
};