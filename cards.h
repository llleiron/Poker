#include <iostream>
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
        Card(const Card& card);
        Card(const Suits& suit, const CardNames& name);
        
        Suits get_suit() const;
        CardNames get_name() const;
        void print_card() const;
        void set_name(const CardNames& name);
        void set_suit(const Suits& suit);

        bool operator >(const Card& card);
        void operator =(const Card& card);
};

#endif
