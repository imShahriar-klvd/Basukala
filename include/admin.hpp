#pragma once

#include "iostream"


class Admin
{
    std::string name;
    std::string password;
    public:
    Admin(std::string n , std::string pass):name(n) , password(pass) {}
    std::string getName() {return name ; }
    std::string getPassword() {return password ;}
};