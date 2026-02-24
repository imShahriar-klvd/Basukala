#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include "city.hpp"

class CityStructure 
{
    std::unordered_map<std::string, City> cities;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> neighborsNode;

public:

    void addCity(std::string& , bool);
    void addRoad(std::string& , std::string& ,int );
    int calculatePathDistance(std::vector<std::string>& path);
    std::vector<std::string> shortestPath( std::string& , std::string&);
    std::string findNearestWarehouse(std::string& destination);
};