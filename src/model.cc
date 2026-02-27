#include "model.hpp"

nlohmann::json Model::saveOneOrder(order* o) // nlohmann has a function array which acn handle multiple items and it has push_back 
{
    nlohmann::json js;

    js["usernmae"] = o->get_costumer()->get_user_name();
    js["fullCost"] = o->get_final_cost();
    js["destination"] = o->get_final_destenition();
    js["time"] = o ->get_insert_time();
    js["products"] = nlohmann::json::array();

    for(auto &pro : o -> get_products())
    {
        js.push_back({pro -> get_name_of_product()});
    }

    return js;

}

void Model::loadOrder() //defenetly has problem will be tasted later
{
    ifstream loadJs("currentOrders.json");

    nlohmann::json ordersData;
    loadJs >> ordersData;

    int biggestTime{};

    for(auto &eachOrder : ordersData)
    {

        int orderTime {eachOrder["time"]};
        if(biggestTime < eachOrder["time"])
        {
            biggestTime = eachOrder["time"];
        }

        string username {eachOrder["username"]};
        int finalCost {eachOrder["fullCost"]};
        string loc {eachOrder["destination"]};

        vector<product*> orderProducts;
 
        for(auto& pro : eachOrder["products"])
        {
            string n {pro["name"]};

            // find it by name
            //orderProducts.push_back(); 
        }

        if(orderProducts.empty())
        {
            return;
        }

        order* temp = new order(finalCost , loc , 0 , orderTime , orderProducts[0] , userMgr.loginUser("username"));

            for(auto& p : orderProducts)
            {
                temp->set_list_of_products(p);
            }

            currentOrders.push(temp);
        }
}


Model::Model()
{
    loadOrder();
}


void Model::acceptCart(user*currentUser , vector<product*> & cart , string destination) //may chnage not final
{
    long long cost = 0;

    for(auto& p : cart)
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
        auto temp {p->get_sold_count() + 1};
        p->set_sold_count(temp);
    }

    order* newOrder = new order(cost, destination, ++globalSerial, ++globalTime, cart[0], currentUser); //may change due to bad order constructor design
    for(size_t i = 1 ; i < cart.size() ; i++)
    {
        newOrder->set_list_of_products(cart[i]);
    }

    currentUser->set_item_bought(newOrder);
    currentOrders.push(newOrder);
}

void Model::deliverOrders() // i dont know if i should print anythingh here
{
    while(!currentOrders.empty())
    {
        order* ord  {currentOrders.top()};
        currentOrders.pop();

        string destination {ord->get_final_destenition()};
        
        user* costumer  {ord->get_costumer()};
        // cout << "order of " << costumer -> getName() << " has been delivered \n";  

        string warehouse {town.findNearestWarehouse(destination)};
        // cout << "from " << warehouse << " to " << destination << endl;

        vector<string> path {town.shortestPath(warehouse , destination)};

        //cout << "complete path\n";
        // for(string& it : path)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        costumer ->set_score( costumer ->get_score() + ord->get_products().size());
        globalTime = 0;
    }

}

Model::~Model()
{
    nlohmann::json saveJs = nlohmann::json::array();

    while(!currentOrders.empty())
    {
        saveJs.push_back(saveOneOrder(currentOrders.top()));
        currentOrders.pop();
    }
    ofstream save("currentOrders.json");
    save << saveJs;

}
