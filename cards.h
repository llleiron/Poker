#include "cardnames.h"
#include "suits.h"

#ifndef cards_h
#define cards_h

class Card{
    private:
        Suits _suit;
        CardNames _name;

    public:
        Card();
        Card(const Suits& suit, const CardNames& name);
        Card(const Card& card);
        
        Suits get_suit() const;
        CardNames get_name() const;
        void print_card() const;
};

#endif