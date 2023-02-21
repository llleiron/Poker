#include "validations.h"

bool validate_players_count(int players_count){
    return (players_count <= 14 && players_count > 1);
}

bool validate_chips(int chips){
    return (chips > 0 && chips <= 1000000);
}

bool validate_small_blind(int small_blind){
    return small_blind > 0;
}