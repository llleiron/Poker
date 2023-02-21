#include <vector>
#include "combinations.h"
#include "cards.h"

#ifndef CombCard_h
#define CombCard_h

class comb_card{
    public:
        comb_card();
        comb_card(const Combinations& combination, const std::vector<Card>& cards);
        void set_comb(const Combinations& combination);
        void set_cards(const std::vector<Card>& cards);
        void print_combination_and_cards() const;
        Combinations get_comb() const;
        std::vector<Card> get_cards() const;
        
    private:
        Combinations _combination;
        std::vector<Card> _cards;

};

#endif