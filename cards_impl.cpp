#include <iostream>
#include "cards.h"

Card::Card() = delete;
Card::Card(const Card& card) = delete;

Card::Card(const Suits& suit, const CardNames& name){
    _suit = suit;
    _name = name;
}

CardNames Card::get_name() const{
    return _name;
}

Suits Card::get_suit() const{
    return _suit;
}

void Card::print_card() const{
    if(_name == CardNames::ACE){std::cout << "ace of ";}
    else if(_name == CardNames::TWO){std::cout << "2 of ";}
    else if(_name == CardNames::THREE){std::cout << "3 of ";}
    else if(_name == CardNames::FOUR){std::cout << "4 of ";}
    else if(_name == CardNames::FIVE){std::cout << "5 of ";}
    else if(_name == CardNames::SIX){std::cout << "6 of ";}
    else if(_name == CardNames::SEVEN){std::cout << "7 of ";}
    else if(_name == CardNames::EIGHT){std::cout << "8 of ";}
    else if(_name == CardNames::NINE){std::cout << "9 of ";}
    else if(_name == CardNames::TEN){std::cout << "10 of ";}
    else if(_name == CardNames::JACK){std::cout << "Jack of ";}
    else if(_name == CardNames::QUEEN){std::cout << "Queen of ";}
    else if(_name == CardNames::KING){std::cout << "King of ";}
    
    if(_suit == Suits::CLUBS){std::cout << "clubs" << "\n";}
    else if(_suit == Suits::DIAMONDS){std::cout << "diamonds" << "\n";}
    else if(_suit == Suits::HEARTS){std::cout << "hearts" << "\n";}
    else if(_suit == Suits::SPADES){std::cout << "spades" << "\n";}
}