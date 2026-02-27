#pragma once

#include <vector>
#include "bsd.hpp"

using namespace std;


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

    product* searchAllProducts(std::string target)
    {
        for(auto &[cat , proBST] : categories)
        {
            Node *targetPro {proBST->search(proBST->get_root() , target)};
            if(targetPro)
            {
                return targetPro->items[0];
            }
        }
        return nullptr;
    }


    ~ProductManager() // not sure what to delete
    {}
};