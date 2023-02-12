// #include <random>
// int generate_random_number(int lhs, int rhs){
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distr(lhs, rhs);
//    return distr(gen);
// }
#include "cards.h"
#include <iostream>


int main(){
    
    Card card(Suits::CLUBS, CardNames::TWO);
    card.print_card();
}