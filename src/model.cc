#include "model.hpp"

void Model::acceptCart(user* currentUser , vector<product*> cart , string destination) //may chnage not final
{
    long long cost = 0;

    for(auto p : cart)
    {
        cost += p->get_price();
    }

    if(currentUser->get_wallet() < cost)
    {
        throw out_of_range("Not enough money\n");
    }

    currentUser->set_wallet_money(currentUser->get_wallet() - cost);
    for(auto p : cart)
    {
        auto temp = p->get_sold_count() + 1;
        p->set_sold_count(temp);
    }

    order* newOrder = new order(cost, destination, ++globalSerial, ++globalTime, cart[0], currentUser); //may change bad order constructor design
    for(size_t i = 1 ; i < cart.size() ; i++)
    {
        newOrder->set_list_of_products(cart[i]);
    }

    currentUser->set_persuches(newOrder);
    currentOrders.push(newOrder);
}
