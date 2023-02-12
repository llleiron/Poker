#include "cardnames.h"
#include "suits.h"

#ifndef cards_h
#define cards_h

class Card{
    private:
        Suits _suit;
        CardNames _name;

    public:
        Card() = delete;
        Card(const Card& card);
        Card(const Suits& suit, const CardNames& name);
        
        Suits get_suit() const;
        CardNames get_name() const;
        void print_card() const;
};

#endif
