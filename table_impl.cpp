#include "table.h"

Table::Table(Card card1,  Card card2, Card card3, Card card4, Card card5){
    _card1 = card1;
    _card2 = card2;
    _card3 = card3;
    _card4 = card4;
    _card5 = card5;
}

Table::Table(Table& table){
    _card1 = table.get_card1();
    _card2 = table.get_card2();
    _card3 = table.get_card3();
    _card4 = table.get_card4();
    _card5 = table.get_card5();
}

void Table::set_cards(Card& card1, Card& card2, Card& card3, Card& card4, Card& card5){
    _card1 = card1;
    _card2 = card2;
    _card3 = card3;
    _card4 = card4;
    _card5 = card5;
}


Card Table::get_card1() const{
    return _card1;
}

Card Table::get_card2() const{
    return _card2;
}

Card Table::get_card3() const{
    return _card3;
}

Card Table::get_card4() const{
    return _card4;
}

Card Table::get_card5() const{
    return _card5;
}
