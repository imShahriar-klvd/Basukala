#pragma once

#include <vector>
#include "bsd.hpp"

using namespace std;



class ProductManager
{
    unordered_map<string , BST*> categories;

    //heap<product> pro;
    //ProductHeap bestSellerHeap;
    //vector<product> allproduct;

public:
    ProductManager(){}

    void addProduct(product *p, string categoryName)
    {
        categories[categoryName]->insert(p);
        //Heap.push(p);
    }

    void removeProduct(int);
    void decreaseProduct(); // use when user shopping


    ~ProductManager() // not sure what to delete
    {}
};