#include <iostream>
#include "cards.h"
#include "deck.h"
#include "player.h"
#include "table.h"
#include "play.h"

int main(){
    play();
        
    std::string flag;
    std::cout << "would you like to play again?: ";
    std::cin >> flag;

    while(flag == "yes"){
        play();
        std::cin >> flag;
    }
    return 0;
}
