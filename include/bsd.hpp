#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "product.hpp"

struct Node
{
    std::string name;
    std::vector<product *> items;
    Node *left{};
    Node *right{};

    explicit Node(product *p)
        : name(p->get_name_of_product())
    {
        if (p == nullptr)
        {
            throw invalid_argument("the node is null cant insert ");
        }
        else
        {

            items.push_back(p);
        }
    }
};

class BST
{
    Node *root;

public:
    BST() : root(nullptr) {}

    void insert(product *p);
    Node *search(Node *node, std::string &target);
    void destroy(Node *node);

    Node *get_root() const { return root; }

    ~BST()
    {
        destroy(root);
    }
};
