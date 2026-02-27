#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "userManager.hpp"
#include "productManager.hpp"
#include "cityStructuer.hpp"
#include "order.hpp"
#include "product.hpp"
#include "user.hpp"
#include <queue>
#include <nlohmann/json.hpp>


class OrderCompare
{
    public:
    bool operator()(order* a , order* b)
    {
        if(a->get_costumer()->get_score() == b->get_costumer()->get_score())
        {
            return a->get_insert_time() > b->get_insert_time(); 
        }

        return a->get_costumer()->get_score() < b->get_costumer()->get_score();
    }
};

class Model 
{
    UserManager userMgr;
    ProductManager productMgr;
    CityStructure town;
    
    int globalTime{};
    int globalSerial{};
    priority_queue<order*, vector<order*>, OrderCompare> currentOrders;

public:

    Model(); //get orders and time and serial from json 
    UserManager& getUserMgr() {return userMgr;}
    ProductManager& getProductManager () {return productMgr;}
    CityStructure& getTown() {return town;}

    void acceptCart(user* currentUser , vector<product*> &cart , string destination);
    void deliverOrders();
    nlohmann::json saveOneOrder(order*);
    void loadOrder();

    ~Model();
};