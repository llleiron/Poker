#include "cards.h"

#ifndef Table_h
#define Table_h

class Table{
    public:
        Table(Card card1,  Card card2, Card card3, Card card4, Card card5);
        Table(Table& table);

        void set_cards(Card& card1, Card& card2, Card& card3, Card& card4, Card& card5);
        
        Card get_card1() const;
        Card get_card2() const;
        Card get_card3() const;
        Card get_card4() const;
        Card get_card5() const;

    private:
        Card _card1;
        Card _card2;
        Card _card3;
        Card _card4;
        Card _card5;
};

#endif