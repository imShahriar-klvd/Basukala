#include<product.hpp>
product::product(string name,int number,int price)
{
    this->set_name_of_product(name);
    this->set_number_of_product(number);
    this->set_price(price);
}
void  product::set_name_of_product(const string name)
{
    this->name_of_product=name;
}
void  product::set_number_of_product(const int number )
{
    this->number_of_product=number;
}
void product:: set_price(const int price)
{
    this->price=price;
}
const  string product ::get_name_of_product()
{
    return this->name_of_product;
}
const int product ::get_number_of_product()
{
    return this->number_of_product;
}
const int  product::get_price()
{
    return this->price;
}
product ::~product()=default;
