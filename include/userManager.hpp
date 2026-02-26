#pragma once
#include "user.hpp"
#include "hash.hpp"
#include <unordered_map>

class UserManager
{
private:
    HashTable usersHash;   
    std::unordered_map<std::string, user*> users;  

public:
    UserManager() = default;
    
    bool registerUser(const std::string& name);
    user* loginUser(const std::string& name);
    void printAllUsers();
    
    ~UserManager();
};