#include "pathfinding.h"
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>

Pathfinding::Pathfinding(int rows, int cols)
    :ROW(rows), COL(cols), wasVisited(rows, std::vector<bool>(cols, false))
{
    srand(static_cast<unsigned int>(time(0)));
}

std::pair<int, int> Pathfinding::GetRandomTile()
{
    int x = rand() % ROW;
    int y = rand() % COL;
    return std::make_pair(x,y);
}

bool Pathfinding::IsValidTile(int x, int y)
{
    return (
        x >= 0 && x < ROW &&
        y >= 0 && y < COL &&
        !wasVisited[x][y]
        );
}

void Pathfinding::MarkAsVisited(int x, int y)
{
    //---> change sprite color to white
    wasVisited[x][y] = true;
}

void Pathfinding::ResetVisited()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            wasVisited[i][j] = false;
        }
    }
}

std::pair<int, int> Pathfinding::GetNeighbors(const std::pair<int, int>& current, std::queue<std::pair<int, int>>& frontier)
{
    std::vector<std::pair<int, int>> directions =
        {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
        };

    int x = current.first;
    int y = current.second;

    for (auto& direction : directions)
    {
        int newX = x + direction.first;
        int newY = y + direction.second;

        if (IsValidTile(newX, newY))
        {
            frontier.push({newX, newY});
            MarkAsVisited(newX, newY);
        }
    }

    return current;
}

std::pair<int, int> Pathfinding::GetRandomFrontier(std::queue<std::pair<int, int>>& frontier)
{
    std::vector<std::pair<int, int>> tempList;

    while (!frontier.empty())
    {
        tempList.push_back(frontier.front());
        frontier.pop();
    }

    if (tempList.empty())
    {
        return {-1, -1};
    }

    std::pair<int, int> chosen = tempList[rand() % tempList.size()];

    for (const auto& tile : tempList)
    {
        frontier.push(tile);
    }

    return chosen;
}

std::vector<std::pair<int, int>> Pathfinding::GenerateField(int startX, int startY, int endX, int endY)
{
    std::cout << "STARTING SEARCH" << std::endl;

    ResetVisited();

    std::queue<std::pair<int, int>> frontier;
    frontier.push({startX, startY});

    wasVisited[startX][startY] = true;

    while (!frontier.empty())
    {
        std::pair<int, int> current = GetRandomFrontier(frontier);
        frontier.pop();

        if (current.first == endX && current.second == endY)
        {
            std::cout << "THE CASTLE IS AT (" << current.first << ", " << current.second << ")" << std::endl;
            return {};
        }

        GetNeighbors(current, frontier);
    }
    return {};
}
