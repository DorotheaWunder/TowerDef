#include "pathfinding.h"
#include "target.h"
#include "sprites.h"
#include "GameMap.h"
#include "GameManager.h"
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <algorithm>

Pathfinding::Pathfinding(int rows, int cols, GameMap* gameMap)
    :ROW(rows), COL(cols), wasVisited(rows, std::vector<bool>(cols, false))
{
    srand(static_cast<unsigned int>(time(0)));
}

void Pathfinding::ChangeTileColor(int row, int col, Color newColor)
{
    if (row >= 0 && row < ROW && col >=0 && col < COL)
    {
        gameMap->grid[row][col]->terrain->sprite.SetColor(newColor);
    }
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
    wasVisited[x][y] = true;
    //ChangeTileColor(x, y, WHITE);
    //gameMap->DrawMap();
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

std::pair<int, int> Pathfinding::GetNeighbors(
    const std::pair<int, int>& current,
    std::queue<std::pair<int, int>>& frontier,
    std::map<std::pair<int, int>, std::pair<int, int> >& cameFrom)
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
            cameFrom[{newX, newY}] = current;
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

std::vector<std::pair<int,int>> Pathfinding::TrackPath(
    const std::map<std::pair<int, int>, std::pair<int, int>>& cameFrom,
    const std::pair<int, int>& start,
    const std::pair<int, int>& goal)
{
    std::vector<std::pair<int, int>> path;
    std::pair<int, int> current = goal;

    while (current != start)
    {
        path.push_back(current);
        current = cameFrom.at(current);
    }

    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return path;
}



std::vector<std::pair<int, int>> Pathfinding::GenerateField(int startX, int startY, const Target& target)
{
    std::cout << "STARTING SEARCH from (" << startX << "," << startY << ") for TARGET of type "
          << static_cast<int>(target.GetTargetType()) << " at (" << target.GetGridPosition().first
          << ", " << target.GetGridPosition().second << ")" << std::endl;

    //WaitTime(0.5);
    ResetVisited();
    std::cout << "-------------------------------------------------------------------->> visited was reset" << std::endl;
    //ChangeTileColor(startX, startY, YELLOW);
    std::cout << "-------------------------------------------------------------------->> tile color was changed" << std::endl;
    //gameMap->DrawMap();
    std::cout << "-------------------------------------------------------------------->> map was redrawn" << std::endl;
    //WaitTime(0.2);


    std::map<std::pair<int, int>, std::pair<int, int>> cameFrom;

    std::queue<std::pair<int, int>> frontier;
    frontier.push({startX, startY});

    wasVisited[startX][startY] = true;

    std::pair<int, int> goalPosition = target.GetGridPosition();


    std::cout << "-------------------------------------------------------------------->> before while loop" << std::endl;
    while (!frontier.empty())
    {
        std::pair<int, int> current = GetRandomFrontier(frontier);
        //ChangeTileColor(current.first, current.second, ORANGE);
        //gameMap->DrawMap();
        // WaitTime(0.2);

        frontier.pop();

        std::cout << "---------------------------------------------------------------->> INSIDE while loop" << std::endl;
        if (current == goalPosition)
        {
            std::cout << "TARGET FOUND at (" << current.first << ", " << current.second << ")" << std::endl;
            //ChangeTileColor(current.first, current.second, RED);
            //gameMap->DrawMap();
            // WaitTime(0.2);
            return TrackPath(cameFrom, {startX, startY}, goalPosition);
        }

        GetNeighbors(current, frontier, cameFrom);
    }
    std::cout << "Nothing to find" << std::endl;
    return {};
}

