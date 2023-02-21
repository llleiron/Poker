#include "utility_funcs.h"

int generate_random_number(int lhs, int rhs){
   srand(time(0));
   int number =  lhs + (rand() % static_cast<int>(rhs - lhs + 1));
   return number;
}

bool operator==(const Card& card1, const Card& card2){
   return (card1.get_name() == card2.get_name()) && (card1.get_suit() == card2.get_suit());
}

Card get_highest_card_for_HIGHCARD(const std::vector<Card>& cards){
   Card max_card(Suits::CLUBS, CardNames::TWO);
   for(auto el: cards){
      if(el > max_card) max_card = el;
   }
   return max_card;
}

int my_count(const std::vector<Card>& cards, const Card& card){
   CardNames cur_card_name = card.get_name();
   int count = 0;
   for(auto el: cards){
      if(el.get_name() == cur_card_name){
         ++count;
      }
   }
   return count;
}

std::vector<Card> get_pair_of_this_card(const std::vector<Card>& cards, const Card& el){
   std::vector<Card> current_cards;

   for(auto elem: cards){
      if(elem.get_name() == el.get_name()){
         current_cards.push_back(elem);
      }
   }
   return current_cards;
}

std::vector<Card> get_highest_pair_if_exists(const std::vector<Card>& cards){
   std::vector<Card> current_combination_cards;

   for(auto el: cards){
      if(my_count(cards, el) == 2){
         if(current_combination_cards.empty()){
            current_combination_cards = get_pair_of_this_card(cards, el);
         }
         else{
            if(el > current_combination_cards[0]){
               current_combination_cards = get_pair_of_this_card(cards, el);
            }
         }
      }
   }

   return current_combination_cards;
}

std::vector<Card> get_second_pair_if_exists(const std::vector<Card>& cards, const std::vector<Card>& first_pair){
   std::vector<Card> current_combination_cards;

   for(auto el: cards){
      if(el == first_pair[0] || el == first_pair[1]) continue;
      if(my_count(cards, el) == 2){
         current_combination_cards = get_pair_of_this_card(cards, el);
      }
   }

   return current_combination_cards;
}

std::vector<Card> get_three_of_a_kind_of_this_card(const std::vector<Card>& cards, const Card& el){
   std::vector<Card> current_cards;

   for(auto elem: cards){
      if(elem.get_name() == el.get_name()){
         current_cards.push_back(elem);
      }
   }

   return current_cards;
}

std::vector<Card> get_three_of_a_kind_if_exists(const std::vector<Card>& cards){
   std::vector<Card> current_combination_cards;

   for(auto el: cards){
      if(my_count(cards, el) == 3){
         current_combination_cards = get_three_of_a_kind_of_this_card(cards, el);
      }
   }
   
   return current_combination_cards;
}

std::vector<Card> get_four_of_a_kind_of_this_card(const std::vector<Card>& cards, const Card& el){
   std::vector<Card> current_cards;

   for(auto elem: cards){
      if(elem.get_name() == el.get_name()){
         current_cards.push_back(elem);
      }
   }

   return current_cards;
}

std::vector<Card> get_four_of_a_kind_if_exists(const std::vector<Card>& cards){
   std::vector<Card> current_combination_cards;

   for(auto el: cards){
      if(my_count(cards, el) == 4){
         current_combination_cards = get_four_of_a_kind_of_this_card(cards, el);
      }
   }
   
   return current_combination_cards;
}

bool there_is_king(const std::vector<Card>& cards){
   for(auto el: cards){
      if(el.get_name() == CardNames::KING){
         return true;
      }
   }
   return false;
}

bool is_straight(const std::vector<Card>& cards){
   int min_value = 20, max_value = -1;
   if(there_is_king(cards)){
      for(auto el: cards){
         if(el.get_name() == CardNames::ACE){
            max_value = 14;
            continue;
         }
         max_value = (static_cast<int>(el.get_name()) > max_value) ? static_cast<int>(el.get_name()) : max_value;
         min_value = (static_cast<int>(el.get_name()) < min_value) ? static_cast<int>(el.get_name()) : min_value;
      }
   }

   else{
      for(auto el: cards){
         max_value = (static_cast<int>(el.get_name()) > max_value) ? static_cast<int>(el.get_name()) : max_value;
         min_value = (static_cast<int>(el.get_name()) < min_value) ? static_cast<int>(el.get_name()) : min_value;
      } 
   }

   return (max_value - min_value == 4);
}

bool is_flush(const std::vector<Card>& cards){
   Suits cur_suit = cards[0].get_suit();

   for(auto el: cards){
      if(el.get_suit() != cur_suit) return false;
   }

   return true;
}

bool is_royale_flush(const std::vector<Card>& cards){
   int flag = 0;

   for(auto el: cards){
      if(el.get_name() == CardNames::ACE || el.get_name() == CardNames::KING) ++flag; 
   }

   return (flag == 2);
}

comb_card get_current_combination_util(const std::vector<Card>& cards){
   comb_card return_value;
   Combinations current_combination = Combinations::HIGHCARD;
   std::vector<Card> current_combination_cards{get_highest_card_for_HIGHCARD(cards)};

   return_value.set_cards(current_combination_cards);
   return_value.set_comb(current_combination);

   std::vector<Card> pair_check = get_highest_pair_if_exists(cards);
   std::vector<Card> three_of_a_kind_check = get_three_of_a_kind_if_exists(cards);
   std::vector<Card> four_of_a_kind_check = get_four_of_a_kind_if_exists(cards);

   if(!pair_check.empty()){
      current_combination = Combinations::PAIR;
      current_combination_cards = pair_check;
      std::vector<Card> two_pair_check = get_second_pair_if_exists(cards, current_combination_cards);

      if(!two_pair_check.empty()){
         current_combination = Combinations::TWOPAIR;
         current_combination_cards.push_back(two_pair_check[0]);
         current_combination_cards.push_back(two_pair_check[1]);
         return_value.set_cards(current_combination_cards);
         return_value.set_comb(current_combination);
         return return_value;
      }

      if(!three_of_a_kind_check.empty()){
         current_combination = Combinations::FULLHOUSE;
         current_combination_cards.push_back(three_of_a_kind_check[0]);
         current_combination_cards.push_back(three_of_a_kind_check[1]);
         current_combination_cards.push_back(three_of_a_kind_check[2]);
         return_value.set_cards(current_combination_cards);
         return_value.set_comb(current_combination);
         return return_value;
      }

      return_value.set_cards(current_combination_cards);
      return_value.set_comb(current_combination);
      return return_value;
   }

   if(!three_of_a_kind_check.empty()){
      current_combination = Combinations::THREEOFAKIND;
      current_combination_cards = three_of_a_kind_check;
      return_value.set_cards(current_combination_cards);
      return_value.set_comb(current_combination);
      return return_value;
   }

   if(!four_of_a_kind_check.empty()){
      current_combination = Combinations::FOUROFAKIND;
      current_combination_cards = four_of_a_kind_check;
      return_value.set_cards(current_combination_cards);
      return_value.set_comb(current_combination);
      return return_value;
   }

   if(is_straight(cards)){
      return_value.set_cards(cards);
      if(is_flush(cards)){
         if(is_royale_flush(cards)){
            return_value.set_comb(Combinations::ROYALFLUSH);
            return return_value;
         }
         return_value.set_comb(Combinations::STRAIGHTFLUSH);
         return return_value;
      }
      return_value.set_comb(Combinations::STRAIGHT);
      return return_value;
   }

   if(is_flush(cards)){
      return_value.set_cards(cards);
      return_value.set_comb(Combinations::FLUSH);
   }

   return_value.set_cards(cards);
   return_value.set_comb(current_combination);
   return return_value;
}


comb_card get_best_combination_of_six_cards(
   const std::vector<Card>& cards1,
   const std::vector<Card>& cards2, 
   const std::vector<Card>& cards3, 
   const std::vector<Card>& cards4, 
   const std::vector<Card>& cards5, 
   const std::vector<Card>& cards6){

   comb_card cards1_comb = get_current_combination_util(cards1);
   comb_card cards2_comb = get_current_combination_util(cards2);
   comb_card cards3_comb = get_current_combination_util(cards3);
   comb_card cards4_comb = get_current_combination_util(cards4);
   comb_card cards5_comb = get_current_combination_util(cards5);
   comb_card cards6_comb = get_current_combination_util(cards6);

   int one, two, three, four, five, six;

   one = static_cast<int>(cards1_comb.get_comb());
   two = static_cast<int>(cards2_comb.get_comb());
   three = static_cast<int>(cards3_comb.get_comb());
   four = static_cast<int>(cards4_comb.get_comb());
   five = static_cast<int>(cards5_comb.get_comb());
   six = static_cast<int>(cards6_comb.get_comb());

   std::vector<int> temp{one, two, three, four, five, six};
   int max_elem = *max_element(temp.begin(), temp.end());

   if(max_elem == one) return cards1_comb;
   if(max_elem == two) return cards2_comb;
   if(max_elem == three) return cards3_comb;
   if(max_elem == four) return cards4_comb;
   if(max_elem == five) return cards5_comb;
   if(max_elem == six) return cards6_comb;
}

comb_card get_best_combination_of_five_cards(
    const comb_card& first, 
    const comb_card& second,
    const comb_card& third,
    const comb_card& fourth,
    const comb_card& fifth){

    int one = static_cast<int>(first.get_comb());
    int two = static_cast<int>(second.get_comb());
    int three = static_cast<int>(third.get_comb());
    int four = static_cast<int>(fourth.get_comb());
    int five = static_cast<int>(fifth.get_comb());

    std::vector<int> temp{one, two, three, four, five};
    int max_elem = *max_element(temp.begin(), temp.end());

    if(max_elem == one) return first;
    if(max_elem == two) return second;
    if(max_elem == three) return third;
    if(max_elem == four) return fourth;
    if(max_elem == five) return fifth;
   }
