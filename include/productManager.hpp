#pragma once

#include <vector>
#include "bsd.hpp"

using namespace std;

//create bst create hep addpro add in bsd and heap remove remove decrease must remove number from array of bsd , and print product 

class ProductManager
{
    unordered_map<string , BST*> categories;

    //heap<product> pro; //all new must be in manager frome file in const and assert data
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