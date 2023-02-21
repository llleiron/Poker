#include "utility_types.h"

comb_card::comb_card(){
    _combination = Combinations::HIGHCARD;
    _cards = std::vector<Card>();
}

comb_card::comb_card(const Combinations& combination, const std::vector<Card>& cards){
    _combination = combination;
    _cards = cards;
}

void comb_card::set_comb(const Combinations& combination){
    _combination = combination;
}

void comb_card::set_cards(const std::vector<Card>& cards){
    _cards = cards;
}

Combinations comb_card::get_comb() const{
    return _combination;
}

std::vector<Card> comb_card::get_cards() const{
    return _cards;
}

void comb_card::print_combination_and_cards() const{
    if(_combination == Combinations::HIGHCARD) std::cout << "HIGHCARD: \n";
    else if(_combination == Combinations::PAIR) std::cout << "PAIR: \n";
    else if(_combination == Combinations::TWOPAIR) std::cout << "TWO PAIR: \n";
    else if(_combination == Combinations::THREEOFAKIND) std::cout << "THREE OF A KIND: \n";
    else if(_combination == Combinations::STRAIGHT) std::cout << "STRAIGHT: \n";
    else if(_combination == Combinations::FLUSH) std::cout << "FLUSH: \n";
    else if(_combination == Combinations::FULLHOUSE) std::cout << "FULL HOUSE: \n";
    else if(_combination == Combinations::FOUROFAKIND) std::cout << "FOUR OF A KIND: \n";
    else if(_combination == Combinations::STRAIGHTFLUSH) std::cout << "STRAIGHT FLUSH: \n";
    else if(_combination == Combinations::ROYALFLUSH) std::cout << "ROYAL FLUSH: \n";

    for(auto el: _cards){
        el.print_card();
    }

    std::cout << "\n";
}