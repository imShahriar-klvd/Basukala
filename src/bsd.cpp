#include "bsd.hpp"

void BST::insert(product* p) 
{
    if (!p)
    {
        throw std::invalid_argument("insert node is not valid ");
    }

    const std::string key = p->get_name_of_product();
    if (key.empty())
    {
        throw std::invalid_argument("key is empty ");
    }

    if (!root) 
    {
        root = new Node(p);
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current) 
    {
        parent = current;

        if (key < current->name) 
        {
            current = current->left;
        }
        else if (key > current->name) 
        {
            current = current->right;
        }
        else 
        {
            current->items.push_back(p);
            return;
        }
    }

    if (key < parent->name)
        parent->left = new Node(p);
    else
        parent->right = new Node(p);
}

Node* BST::search(Node* node, std::string& target)
{
    if (!node)
        return nullptr;

    if (target == node->name)
        return node;

    if (target < node->name)
        return search(node->left, target);

    return search(node->right, target);
}

void BST::destroy(Node* node) 
{
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
