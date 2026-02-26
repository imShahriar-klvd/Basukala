#include "maxheap.hpp"


bool max_heap::greater_than(product *a, product *b)
{
    return a->get_sold_count() > b->get_sold_count();
}

void max_heap::heapify_up(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (!greater_than(heap[index], heap[parent]))
            break;

        std::swap(heap[index], heap[parent]);
        index = parent;
    }
}

void max_heap::heapify_down(int index)
{
    int n = heap.size();
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < n && greater_than(heap[left], heap[largest]))
            largest = left;
        if (right < n && greater_than(heap[right], heap[largest]))
            largest = right;

        if (largest == index)
            break;

        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}

void max_heap::collect_from_bst(Node *node)
{
    if (!node)
        return;

    collect_from_bst(node->left);

    for (product *p : node->items)
        insert(p);

    collect_from_bst(node->right);
}

max_heap::max_heap(const std::unordered_map<std::string, BST *> &categories)
{
    for (const auto &pair : categories)
    {
        BST *tree = pair.second;
        if (tree)
        {
            collect_from_bst(tree->get_root());
        }
    }
}

bool max_heap::empty() const
{
    return heap.empty();
}

int max_heap::size() const
{
    return heap.size();
}

product *max_heap::top() const
{
    if (heap.empty())
        return nullptr;
    return heap[0];
}

void max_heap::insert(product *p)
{
    if (!p)
        throw std::invalid_argument("null product cannot be inserted");

    heap.push_back(p);
    heapify_up(heap.size() - 1);
}

void max_heap::pop()
{
    if (heap.empty())
        return;

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
        heapify_down(0);
}
void max_heap::remove(product *p)
{
    if (!p)
        return;

    int index = -1;
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i] == p)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return; 

    
    heap[index] = heap.back();
    heap.pop_back();

    
    if (index < heap.size())
    {
        heapify_up(index);
        heapify_down(index);
    }
}