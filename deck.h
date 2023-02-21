#include <vector>
#include <random>
#include <algorithm>
#include "cards.h"
#include "utility_funcs.h"

#ifndef DECK_H
#define DECK_H

class Deck{
    private:
        std::vector<Card> _deck;
    
    public:
        Deck();
        void setup();
        void shuffle();
        Deck(const Deck& deck);
        void delete_card(Card& card);
        int find_card(const Card& card) const;
        Card get_random_card();
        std::vector<Card> get_deck() const;
};

#endif
