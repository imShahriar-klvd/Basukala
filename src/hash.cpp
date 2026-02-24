#include "hash.hpp"

HashTable::HashTable()
{
    table.resize(size_of_tabel);
}

int HashTable::hash_function(const string key)
{
    long long int sum = 0;
    for (char c : key)
    {
        sum += c;
    }
    return sum % size_of_tabel;
}

void HashTable::insert(const string key)
{
    long long int index = hash_function(key);
    table[index].push_back(key);
}

bool HashTable::search(const string key)
{
    long long int index = hash_function(key);
    for (auto &k : table[index])
    {
        if (k == key)
        {
            return true;
        }
    }
    return false;
}