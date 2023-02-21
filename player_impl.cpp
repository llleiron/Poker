#include "player.h"

Player::Player(Card card1,  Card card2, int chips){
    _card1 = card1;
    _card2 = card2;
    _chips = chips;
}

Player::Player(const Player& player){
    _card1 = player.get_card1();
    _card2 = player.get_card2();
    _chips = player.get_chips();
}

void Player::set_cards(const Card& card1, const Card& card2){
    _card1 = card1;
    _card2 = card2;
}

void Player::set_chips(int chips){
    _chips = chips;
}

Card Player::get_card1() const{
    return _card1;
}

Card Player::get_card2() const{
    return _card2;
}

int Player::get_chips() const{
    return _chips;
}

void Player::call(int value){
    _chips -= value;
}

void Player::raise(int value){
    _chips -= value;
}

void Player::fold(){
    return;
}

void Player::check() const{
    return;
}

void Player::allin() {
    _chips = 0;
}

comb_card Player::get_current_combination(){
    comb_card return_value;
    std::vector<Card> cur_cards;

    if(_card1.get_name() == _card2.get_name()){
        cur_cards.push_back(_card1);
        cur_cards.push_back(_card2);
        return_value.set_cards(cur_cards);
        return_value.set_comb(Combinations::PAIR);
        return return_value;
    } 

    Card cur_card = (_card1 > _card2) ? _card1 : _card2;
    cur_cards.push_back(cur_card);

    return_value.set_cards(cur_cards);
    return_value.set_comb(Combinations::HIGHCARD);
    return return_value;
}

comb_card Player::get_current_combination(Card card1, Card card2, Card card3){
    std::vector<Card> cards{_card1, _card2, card1, card2, card3};
    return get_current_combination_util(cards);
}   

comb_card Player::get_current_combination(Card card1, Card card2, Card card3, Card card4){
    std::vector<Card> cards1{_card1, _card2, card1, card2, card3};
    std::vector<Card> cards2{card4, _card2, card1, card2, card3};
    std::vector<Card> cards3{_card1, card4, card1, card2, card3};
    std::vector<Card> cards4{_card1, _card2, card4, card2, card3};
    std::vector<Card> cards5{_card1, _card2, card1, card4, card3};
    std::vector<Card> cards6{_card1, _card2, card1, card2, card4};
    
    return get_best_combination_of_six_cards(cards1, cards2, cards3, cards4, cards5, cards6);
}

comb_card Player::get_current_combination(Card card1, Card card2, Card card3, Card card4, Card card5){
    
    return get_best_combination_of_five_cards(
        get_current_combination(card1, card2, card3, card4),
        get_current_combination(card5, card2, card3, card4),
        get_current_combination(card1, card5, card3, card4),
        get_current_combination(card1, card2, card5, card4),
        get_current_combination(card1, card2, card3, card5)
    );
}