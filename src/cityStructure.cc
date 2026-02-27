#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <fstream>
#include "cityStructuer.hpp"
#include <nlohmann/json.hpp>

using namespace std;

CityStructure::CityStructure()
{
    ifstream file("../sources/location.json");
    nlohmann::json data;
    file >> data;
    
    for (auto& [cityName, cityData] : data["cities"].items()) 
    {
        bool isWarehouse = cityData["isWarehouse"];
        string temp = cityName;
        addCity(temp , isWarehouse);
    }
    
    for (auto& [cityName, cityData] : data["cities"].items()) 
    {
        if (cityData.contains("roads")) 
        {
            string temp {cityName};
            for (auto& [neighbor, distance] : cityData["roads"].items()) 
            {
                string tempNeghbor = neighbor;
                addRoad(temp, tempNeghbor, distance);
            }
        }
    }
}



void CityStructure::addCity(std::string& n, bool warehouse )
{
    cities.insert({n, City(n, warehouse)});
}

void CityStructure::addRoad(string& first, string& second, int distance)
{
    neighborsNode[first].push_back({second, distance});
    neighborsNode[second].push_back({first, distance});
}

int CityStructure::calculatePathDistance(vector<string>& path)  
{
    int sum {};

    for (size_t i = 0; i + 1 < path.size(); ++i)
    {
        for (auto& neighbor : neighborsNode[path[i]])
        {
            if (neighbor.first == path[i+1])
            {
                sum += neighbor.second;
                break;
            }
        }
    }

    return sum;
}
vector<string> CityStructure::shortestPath( string& start, string& end)
{
    unordered_map<std::string, int> distinations;
    unordered_map<std::string, bool> visited;
    unordered_map<std::string, std::string> parent;

    for (auto& [cityName , neighborList] : neighborsNode)
    {
        distinations[cityName] = std::numeric_limits<int>::max(); // it should be the biggest eadge in the graph
        visited[cityName] = false;
    }

    distinations[start] = {};
    for (size_t i = 0; i < neighborsNode.size(); i++)
    {
        string current;
        int minDist = numeric_limits<int>::max();

        for (auto& [cityName , weight] : distinations)
        {
            if (!visited[cityName] && weight < minDist)
            {
                minDist = weight;
                current = cityName;
            }
        }

        if (current.empty())
        {
            break;
        }
        visited[current] = true;

        for (auto& neighbor : neighborsNode[current])
        {
            string next = neighbor.first;
            int weight = neighbor.second;

            if (!visited[next] && distinations[current] + weight < distinations[next])
            {
                distinations[next] = distinations[current] + weight;
                parent[next] = current;
            }
        }
    }

    vector<string> path;
    if (distinations[end] == numeric_limits<int>::max())
        return path;

    string current = end;

    while (current != start)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}


    
string CityStructure::findNearestWarehouse(string& destination)
{
    int minDistance = numeric_limits<int>::max();
    string nearest;

    for (auto& [cityName , city] : cities)
    {
        if (!city.getIsWarehouse())
            continue;

        string temp {cityName};

        auto path = shortestPath(temp, destination);
        int total = calculatePathDistance(path);

        if (total < minDistance)
        {
            minDistance = total;
            nearest = cityName;
        }
    }

    return nearest;
}


