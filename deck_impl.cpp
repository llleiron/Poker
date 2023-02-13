#include "deck.h"
#include "utility_funcs.h"
#include <algorithm>


Deck::Deck(){
    for(int i = (int)Suits::CLUBS; i <= (int)Suits::SPADES; ++i){
        for(int j = (int)CardNames::ACE; j <= (int)CardNames::KING; ++j){
            Card current_card(static_cast<Suits>(i), static_cast<CardNames>(j));
            _deck.push_back(current_card);
        }
    }
}

void Deck::setup(){
    for(int i = (int)Suits::CLUBS; i <= (int)Suits::SPADES; ++i){
        for(int j = (int)CardNames::ACE; j <= (int)CardNames::KING; ++j){
            Card current_card(static_cast<Suits>(i), static_cast<CardNames>(j));
            _deck.push_back(current_card);
        }
    }
}

void Deck::delete_card(Card& card){
    auto found = find_card(card);
    if(found == -1) return;

    _deck.erase(_deck.begin() + found);
}

int Deck::find_card(const Card& card) const{
    for(int i = 0; i < _deck.size(); ++i){
        if(_deck[i].get_name() == card.get_name() && _deck[i].get_suit() == card.get_suit()) return i;
    }
    
    return -1;
}

std::vector<Card> Deck::get_deck() const{
    return _deck;
}

Card Deck::get_random_card(){
    if(_deck.size() == 0){
        throw();
    }
    Suits suit = static_cast<Suits>(generate_random_number(1, 4));
    CardNames name = static_cast<CardNames>(generate_random_number(1, 13));

    Card cur_card(suit, name);
    
    while(find_card(cur_card) == -1){
        suit = static_cast<Suits>(generate_random_number(1, 4));
        name = static_cast<CardNames>(generate_random_number(1, 13));
        cur_card.set_name(name);
        cur_card.set_suit(suit);
    }

    return cur_card;
}
