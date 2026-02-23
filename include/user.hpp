#ifndef USER_HPP
#define USER_HPP
#include<string>
#include<iostream>
#include<bits/stdc++.h>
#include<nlohmann/json.hpp>
using namespace std;
class user
{
private:
string user_name="";
 long long int wallet=0;
long long int score=0;



public:

user(string,long long int wallet,long long int);
void set_user_name( const string);
void set_wallet_money(const  long long int);
void set_score(const long long int);
 const string get_user_name();
 const long long int get_wallet();
 const long long int get_score();


};

#endif 