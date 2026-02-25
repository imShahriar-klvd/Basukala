#include "product.hpp"

product::product(string name, int number, int price)
{
    this->set_name_of_product(name);
    this->set_number_of_product(number);
    this->set_price(price);
}
void product::set_name_of_product(const string name)
{
    this->name_of_product = name;
}
void product::set_number_of_product(const int number)
{
    if (number < 0)
    {
        throw invalid_argument("the number of the product is not valid to sest ");
    }
    else
    {
        this->number_of_product = number;
    }
}
void product::set_price(const int price)
{
    if (price < 0)
    {
        throw invalid_argument("the price of product  is not valid to set ");
    }
    else
    {
        this->price = price;
    }
}
 string product ::get_name_of_product()const
{
    return this->name_of_product;
}
 int product ::get_number_of_product() const
{
    return this->number_of_product;
}
 int product::get_price()const
{
    return this->price;
}
