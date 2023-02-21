#include <random>
#include <ctime>
#include <unordered_map>
#include <algorithm>
#include "utility_types.h"
#include "combinations.h"
#include "cards.h"

int generate_random_number(int lhs, int rhs);
int my_count(const std::vector<Card>& cards, const Card& card);

bool operator==(const Card& card1, const Card& card2);
bool there_is_king(const std::vector<Card>& cards);
bool is_straight(const std::vector<Card>& cards);
bool is_flush(const std::vector<Card>& cards);
bool is_royale_flush(const std::vector<Card>& cards);
Card get_highest_card_for_HIGHCARD(const std::vector<Card>& cards);

std::vector<Card> get_pair_of_this_card(const std::vector<Card>& cards, const Card& el);
std::vector<Card> get_highest_pair_if_exists(const std::vector<Card>& cards);
std::vector<Card> get_second_pair_if_exists(const std::vector<Card>& cards, const std::vector<Card>& first_pair);
std::vector<Card> get_three_of_a_kind_if_exists(const std::vector<Card>& cards);
std::vector<Card> get_three_of_a_kind_of_this_card(const std::vector<Card>& cards, const Card& el);
std::vector<Card> get_four_of_a_kind_if_exists(const std::vector<Card>& cards);
std::vector<Card> get_four_of_a_kind_of_this_card(const std::vector<Card>& cards, const Card& el);

comb_card get_current_combination_util(const std::vector<Card>& cards);
comb_card get_best_combination_of_six_cards(
    const std::vector<Card>& cards1,
    const std::vector<Card>& cards2, 
    const std::vector<Card>& cards3, 
    const std::vector<Card>& cards4, 
    const std::vector<Card>& cards5, 
    const std::vector<Card>& cards6);

comb_card get_best_combination_of_five_cards(
    const comb_card& first, 
    const comb_card& second,
    const comb_card& third,
    const comb_card& fourth,
    const comb_card& fifth);