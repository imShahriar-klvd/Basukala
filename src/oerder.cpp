#include"order.hpp"

void order:: set_final_cost(const long long int cost)
{
    if (cost < 0)
    {
        throw invalid_argument("the final cost is not valid ");
    }
    else
    {
        this->final_cost=cost;
    }
    
    
}
void order:: set_final_destenition(const std::string dest)
{
    this->final_destinition=dest;
}
void order::set_serial_number(const long long int number)
{
    if (number<0)
    {
        throw invalid_argument("the serial number is not valid ");
    }
    else
    {
        this->serial_number=number;
    }
    
    
}
void  order::set_insert_time(const long long int time)
{
    if (time<0)
    {
        throw invalid_argument("the time is not valid ");
    }
    else
    {
        this->insert_time=time;
    }
    
    
}
void  order::set_list_of_products( product * prod)
{
    this->list_of_products.push_back(prod);
}
 std::string  order::get_final_destenition() const 
 {
    return this->final_destinition;
 }
 long long int  order::get_serial_number()const 
 {
    return this->serial_number;
 }
 long long int  order::get_insert_time() const 
 {
    return this->insert_time;
 }
 long long int order:: get_final_cost()const
 {
    return this->final_cost;
 }
 vector<product *>order::get_products()const
 {
    return this->list_of_products;
 }
order::order(long long int cost,string des,long long int serial,long long int insert,product * prod)
{
    set_final_cost(cost);
    set_final_destenition(des);
    set_serial_number(serial);
    set_insert_time(insert);
    set_list_of_products(prod);
}
