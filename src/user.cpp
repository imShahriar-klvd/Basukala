#include "user.hpp"
#include"product.hpp"
user::user(string name, long long int wallet, long long int score)
{
    this->set_user_name(name);
    this->set_wallet_money(wallet);
    this->set_score(score);
}
void user::set_user_name(const string name)
{
    this->user_name = name;
}
void user::set_wallet_money(const long long int wallet)
{
    if (wallet < 0)
    {
        throw invalid_argument("the wallet money is not valid to set ");
    }
    else
    {
        this->wallet = wallet;
    }
}
void user::set_score(const long long int score)
{
    if (score < 0)
    {
        throw invalid_argument("the user score is not valid to set ");
    }
    else
    {
        this->score=score;
    }
    
}
  string user:: get_user_name() const
 {
    return this->user_name;
 }
  long long int user:: get_wallet() const
{
        return this->wallet;

}
  long long int user:: get_score() const
 {
    return this->score;
 }
  void user::set_item_bought(order * ord)
  {
    this->item_bought.push_back(ord);
  }
    void user:: set_persuches(product * ord1)
    {
        this->persuches.push_back(ord1);
    }
vector<order *>user::get_item_bought()const
{
    return this->item_bought;
}
vector<product *> user::get_persuches()const
{
    return this->persuches;
}

