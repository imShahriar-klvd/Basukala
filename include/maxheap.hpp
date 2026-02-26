#pragma once
#include<bits/stdc++.h>
#include "product.hpp"
#include "bsd.hpp"

class max_heap
{
private:
    std::vector<product*> heap;

    bool greater_than(product* a, product* b);

    void heapify_up(int index);
    void heapify_down(int index);

    void collect_from_bst(Node* node);

public:
  

    explicit max_heap(const std::unordered_map<std::string, BST*>& categories);

    bool empty() const;
    int size() const;

    product* top() const;

    void insert(product* p);
    void pop();
    void remove(product* p);
};