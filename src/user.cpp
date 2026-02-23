#include <user.hpp>
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
    if (this->wallet < 0)
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
 const string user:: get_user_name()
 {
    return this->user_name;
 }
 const long long int user:: get_wallet()
{
        return this->wallet;

}
 const long long int user:: get_score()
 {
    return this->score;
 }
