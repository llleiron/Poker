#include <unordered_map>
#include "cards.h"
#include "combinations.h"
#include "utility_funcs.h"
#include "utility_types.h"
#ifndef Player_h
#define Player_h

class Player{
    public:
        Player(Card card1,  Card card2, int chips);
        Player(const Player& player);

        void set_cards(const Card& card1, const Card& card2);
        void set_chips(int chips);
        
        Card get_card1() const;
        Card get_card2() const;
        int get_chips() const;

        void check() const;
        void raise(int value);
        void fold();
        void call(int value);
        void allin();

        comb_card get_current_combination();
        comb_card get_current_combination(Card card1, Card card2, Card card3);
        comb_card get_current_combination(Card card1, Card card2, Card card3, Card card4);
        comb_card get_current_combination(Card card1, Card card2, Card card3, Card card4, Card card5);

    private:
        Card _card1;
        Card _card2;
        int _chips;
};

#endif