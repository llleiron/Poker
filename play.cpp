#include "play.h"
   
void show_cards(const std::vector<Player>& players){
    for(int i = 0; i < players.size(); ++i){
        std::cout << "player " << i + 1 << " these are your cards, whenever you memorize it, type ok: ";
        std::cout << "\n";
        
        players[i].get_card1().print_card();
        players[i].get_card2().print_card();
        std::string flag = "";
        std::cin >> flag;

        while(flag != "ok"){
            std::cout << "Enter ok: ";
            std::cin >> flag;
        }

        if(i != players.size() - 1){
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "Next player come near the screen.";
        }
        sleep(2);
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}

int get_blind(){
    int small_blind = 0;
    std::cout << "What is the small blind?: ";
    std::cin >> small_blind;

    while(!validate_small_blind(small_blind)){
        std::cout << "Inappropriate small blind, enter again: ";
        std::cin >> small_blind;
    }

    return small_blind;
}

void set_chips_and_cards(std::vector<Player>& players, int players_count, Deck& deck){
    int chips = 0;
    Player temp(deck.get_random_card(), deck.get_random_card(), chips);
    std::cout << "How many chips does player number " << 1 << " have? (max 1000000): ";
    std::cin >> chips;
    temp.set_chips(chips);
    while(!validate_chips(chips)){
        std::cout << "Inappropriate amount of chips, enter again: ";
        std::cin >> chips;
    }

    players.push_back(temp);

    for(int i = 1; i < players_count; ++i){
        std::cout << "How many chips does player number " << i + 1 << " have?(max 1000000): ";
        std::cin >> chips;

        while(!validate_chips(chips)){
            std::cout << "Inappropriate amount of chips, enter again: ";
            std::cin >> chips;
        }

        temp.set_cards(deck.get_random_card(), deck.get_random_card());
        temp.set_chips(chips);
        players.push_back(temp);
    }
}

int get_players_count(){
    int players_count = 0;

    std::cout << "How many players are there?: ";
    std::cin >> players_count;
    
    while (!validate_players_count(players_count))
    {
        std::cout << "Inappropriate amount of players, enter again: ";
        std::cin >> players_count;
    }
    std::cout << "Players count accepted." << "\n";
    return players_count;
}

int cur_circle(std::vector<Player>& players, Table& table, int blind, std::string stage, int& pot){
    int  amount_to_call = blind;
    bool fold_flag = false;
    
    if(stage == "first"){
        for(int i = 0; i < players.size(); ++i){
            std::cout << "Player number " << i + 1 << " chips after blind: ";
            players[i].call(amount_to_call);

            pot += blind;
            if(players[i].get_chips() < 0){
                pot += players[i].get_chips();
                players[i].set_chips(0);
            }

            std::cout << players[i].get_chips() << "\n";
        }
    }

    amount_to_call = 0;
    int amount_to_raise = 0;

    std::string decision;

    std::cout << "Player number 1 your turn, options are: FOLD, CHECK, RAISE, ALLIN, SEE_CURRENT_COMBINATION, SEE_CURRENT_CHIPS: ";
    std::cin >> decision;

    comb_card comb = players[0].get_current_combination();
    while(decision == "SEE_CURRENT_COMBINATION" || decision == "SEE_CURRENT_CHIPS"){
        if(decision == "SEE_CURRENT_COMBINATION"){
            if(stage == "first")
                comb_card comb =  players[0].get_current_combination();
            else if(stage == "flop")
                comb_card comb = players[0].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3());
            else if(stage == "turn")
                comb_card comb = players[0].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4());
            else if(stage == "river")
                comb_card comb = players[0].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4(), table.get_card5());
            
            comb.print_combination_and_cards();
        }
        else{
            std::cout << "Your chips: " << players[0].get_chips() << "\n";      
        }
        std::cout << "Player number 1 your turn, options are: FOLD, CHECK, RAISE, ALLIN, SEE_CURRENT_COMBINATION, SEE_CURRENT_CHIPS: ";
        std::cin >> decision;
    }
    
    if(decision == "RAISE"){
        std::cout << "Amount to raise?: ";
        std::cin >> amount_to_raise;
        while(players[0].get_chips() < amount_to_raise){
            std::cout << "Invalid amount, enter again: ";
            std::cin >> amount_to_raise;
        }

        players[0].set_chips(players[0].get_chips() - amount_to_raise);
        pot += amount_to_raise;
        amount_to_call = amount_to_raise;
        amount_to_raise = 0;
    }

    else if(decision == "ALLIN"){
        pot += players[0].get_chips();
        amount_to_call = players[0].get_chips();
        players[0].set_chips(0);
    }

    else if(decision == "FOLD"){
        fold_flag = true;
        std::cout << "Player number 1 folded !, now each players index is minused by 1 be careful! \n";
        players.erase(players.begin());
    }

    std::vector<int> indxs_to_fold;
    for(int i = fold_flag ? 0 : 1; i < players.size(); ++i){
        if(amount_to_call != 0){
            std::cout << "Player number " << i + 1 << " you have to call " << amount_to_call << " CALL, FOLD, SEE_CURRENT_COMBINATION, SEE_CURRENT_CHIPS: ";
            std::cin >> decision;
            while(decision == "SEE_CURRENT_COMBINATION" || decision == "SEE_CURRENT_CHIPS"){
                if(decision == "SEE_CURRENT_COMBINATION"){
                    if(stage == "first")
                        comb_card comb =  players[i].get_current_combination();
                    else if(stage == "flop")
                        comb_card comb = players[i].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3());
                    else if(stage == "turn")
                        comb_card comb = players[i].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4());
                    else if(stage == "river")
                        comb_card comb = players[i].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4(), table.get_card5());
            
                    comb.print_combination_and_cards();
                }
                else{
                    std::cout << "Your chips: " << players[i].get_chips() << "\n";      
                }
                std::cout << "Player number " << i + 1 << " you have to call " << amount_to_call << " CALL, FOLD, SEE_CURRENT_COMBINATION, SEE_CURRENT_CHIPS: ";
                std::cin >> decision;
            }
            if(decision == "CALL"){
                if(players[i].get_chips() < amount_to_call){
                    pot += players[i].get_chips();
                    players[i].set_chips(0);
                }
                else{
                    pot += amount_to_call;
                    players[i].set_chips(players[i].get_chips() - amount_to_call);
                }
            }
            if(decision == "FOLD"){
                indxs_to_fold.push_back(i);
                std::cout << "Player number " << i + 1 << " folded, so everybodys index who was after him is minused by 1\n";
            }
        }
        else{
            std::cout << "Player number " << i + 1 << " your turn, options are: " <<  "CHECK, FOLD, SEE_CURRENT_COMBINATION, SEE_CURRENT_CHIPS: ";
            std::cin >> decision;
            while(decision == "SEE_CURRENT_COMBINATION" || decision == "SEE_CURRENT_CHIPS"){
                if(decision == "SEE_CURRENT_COMBINATION"){
                    comb_card comb =  players[i].get_current_combination();
                    comb.print_combination_and_cards();
                }
                else{
                    std::cout << "Your chips: " << players[i].get_chips() << "\n";      
                }
                std::cout << "Player number " << i + 1 << " your turn, options are: " <<  "CHECK, FOLD, SEE_CURRENT_COMBINATION, SEE_CURRENT_CHIPS: ";
                std::cin >> decision;
            }
            if(decision == "FOLD"){
                indxs_to_fold.push_back(i);
                std::cout << "Player number " << i + 1 << " folded so everybody's index who was after him is minused by 1\n";
            }
        }
    }

    for(auto el: indxs_to_fold){
        players.erase(std::next(players.begin(), el));
    }

    return pot;
}

int get_the_winner(std::vector<Player>& players, Table& table){
    int current_winner = 0;
    comb_card current_combination = players[0].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4(), table.get_card5());
    Combinations cur = current_combination.get_comb();
    comb_card _temp = current_combination;
    Combinations temp = cur;

    for(int i = 0; i < players.size(); ++i){
        _temp = players[i].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4(), table.get_card5());
        temp = _temp.get_comb();

        if(static_cast<int>(temp) > static_cast<int>(cur)){
            current_winner = i;
            current_combination = _temp;
            cur = temp;
        }
    }

    return current_winner;
}

void cur_game(std::vector<Player>& players, Table& table, int blind){
    std::string cur_stage = "first";
    int pot = 0;
    std::vector<int> indxs_to_delete;

    cur_circle(players, table, blind, cur_stage, pot);
    if(players.size() > 1){
         
        std::cout << "The flop is: \n";

        table.get_card1().print_card();
        table.get_card2().print_card();
        table.get_card3().print_card();

        cur_stage = "flop";
        cur_circle(players, table, blind, cur_stage, pot);
    }

    if(players.size() > 1){
        std::cout << "The turn is: \n";

        table.get_card1().print_card();
        table.get_card2().print_card();
        table.get_card3().print_card();
        table.get_card4().print_card();

        cur_stage = "turn";
        cur_circle(players, table, blind, cur_stage, pot);
    }
    
    if(players.size() > 1){
        std::cout << "The river is: \n";

        table.get_card1().print_card();
        table.get_card2().print_card();
        table.get_card3().print_card();
        table.get_card4().print_card();
        table.get_card5().print_card();

        cur_stage = "river";
        cur_circle(players, table, blind, cur_stage, pot);
    }
    
    int winner = get_the_winner(players, table);

    players[winner].set_chips(players[get_the_winner(players, table)].get_chips() + pot);

    std::cout << "Player number " << winner + 1 << " won with the combination: \n";
    comb_card winner_comb = players[winner].get_current_combination(table.get_card1(), table.get_card2(), table.get_card3(), table.get_card4(), table.get_card5());
    winner_comb.print_combination_and_cards();

    for(int i = 0; i < players.size(); ++i){
        std::cout << "Player number " << i + 1 << " chips: ";
        std::cout << players[i].get_chips() << "\n";
    }
}

void play(){
    Deck deck;
    deck.shuffle();

    int players_count = 0, chips = 0, current_count = 0, 
        pot = 0, current_raise = 0, blind = 0;


    std::vector<Player> players;

    players_count = get_players_count();
    set_chips_and_cards(players, players_count, deck);
    show_cards(players);

    blind = get_blind();



    std::cout << "The game is starting !!!" << '\n';
    std::cout << "This is not normal poker, let's see what are the rules: \n";
    std::cout << "Ok, so only player number 1 can make raises and there are not reraises, everything else is the same \n";
    Table table(deck.get_random_card(), deck.get_random_card(), deck.get_random_card(), deck.get_random_card(), deck.get_random_card());

    cur_game(players, table, blind);
}