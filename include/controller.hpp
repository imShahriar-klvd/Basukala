#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "model.hpp"
#include "admin.hpp"

using namespace std;

class Controller 
{
    Model system;    
    Admin admin;
    user *currentUser {nullptr};
    //here we should have a class for i/o

    public:

    //Controller(){} -> give admin to it user will be insialize with login

    void mainMenu();
    void adminMenu();
    void userMenu();


};