#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class order;

class user
{
private:
string user_name="";
 long long int wallet=0;
long long int score=0;
vector<order*> item_bought;
vector<order*>persuches;

public:

user(string,long long int wallet,long long int);
void set_user_name( const string);
void set_wallet_money(const  long long int);
void set_score(const long long int);
  string get_user_name() const ;
  long long int get_wallet() const ;
  long long int get_score() const ;
  void set_item_bought(order * ord);
    void set_persuches(order * ord1);
vector<order *>get_item_bought()const;
vector<order *>get_persuches()const;



};

#endif 