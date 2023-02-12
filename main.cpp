// #include <random>
// int generate_random_number(int lhs, int rhs){
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distr(lhs, rhs);
//    return distr(gen);
// }
#include "cards.h"
#include "deck.h"
#include <iostream>


int main(){
    
    Card card(Suits::DIAMONDS, CardNames::FOUR);
    Card card1(Suits::DIAMONDS, CardNames::TWO);
    Deck my_deck;

    my_deck.delete_card(card);
    std::cout << my_deck.find_card(card);
    std::vector<Card> current_deck = my_deck.get_deck();
    
    // for(auto el: current_deck){
    //     el.print_card();
    // }
}
