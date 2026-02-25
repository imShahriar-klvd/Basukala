#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class product
{
private:
string name_of_product;
int number_of_product;
int price;


public:
product(string,int,int);
void set_name_of_product(const string);
void set_number_of_product(const int );
void set_price(const int);
 string get_name_of_product() const;
 int get_number_of_product() const;
 int get_price() const ;
~product()=default;



};



#endif