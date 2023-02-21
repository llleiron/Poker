#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "deck.h"
#include "player.h"
#include "validations.h"
#include "table.h"
#include "utility_types.h"

void play();
void show_cards(const std::vector<Player>& players);
void set_chips_and_cards(const std::vector<Player>& players, int players_count, Deck& deck);
void cur_game(std::vector<Player>& players, Table& table, int small_blind, int big_blind);
int cur_circle(std::vector<Player>& players, Table& table, int small_blind, int blind, std::string stage, int& pot);
int get_blind();
int get_players_count();
int get_the_winner(std::vector<Player>& players, Table& table);