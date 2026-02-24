#pragma once

#include <iostream>


class City
{

    std::string name;
    bool isWarehouse;
    public:
    City(std::string n , bool warehouse): name(n) , isWarehouse(warehouse){}
    std::string getName() {return name;}
    bool getIsWarehouse() { return isWarehouse; }
    

};