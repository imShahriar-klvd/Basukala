#ifndef ORDER_HPP
#define ORDER_HPP
#include<bits/stdc++.h>
#include"user.hpp"
#include"product.hpp"
#include<string>
using namespace std;
class order
{
private:
long long int final_cost=0;
vector<product *>list_of_products;
std::string final_destinition="";
long long int serial_number=0;
long long int insert_time=0;

public:
void set_final_cost(const long long int);
void set_final_destenition(const std::string);
void set_serial_number(const long long int);
void set_insert_time(const long long int);
void set_list_of_products( product *);
 std::string get_final_destenition() const ;
 long long int get_serial_number()const ;
 long long int get_insert_time() const ;
 long long int get_final_cost()const;
 vector<product *>get_products()const;
~order()=default;
order(long long int cost,std::string des,long long int serial,long long int insert,product * prod);

};



#endif