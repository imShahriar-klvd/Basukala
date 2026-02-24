#ifndef HASH_HPP
#define HASH_HPP
#include<bits/stdc++.h>
using namespace std;
class HashTable {
private:
     const  long long int size_of_tabel = 1000; 
    vector<list<string>> table;

    int hash_function(const string key);

public:
    HashTable();

    void insert(const string key);

    
    bool search(const string key);

    
    
};

#endif 