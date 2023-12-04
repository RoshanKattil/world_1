#ifndef SHOW_STUFF
#define SHOW_STUFF

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>
#include <algorithm>

void displayHowToPlay() 
{
    std::cout << "=============================================\n";
    std::cout << "                 HOW TO PLAY\n";
    std::cout << "=============================================\n";
    std::cout << "Guess the Wordle in 6 tries.\n\n";
    std::cout << "HOW TO PLAY:\n";
    std::cout << "- Each guess must be a valid 5 letter word.\n";
    std::cout << "- The color of the tiles will change to show\n";
    std::cout << "  you how close your guess was to the word.\n\n";
    
    // Example of colored tiles
    std::cout << " ---  ---  ---  ---\n";
    std::cout << "| \033[1;32mW\033[0m || E || A || R || Y |\n";
    std::cout << " ---  ---  ---  ---\n";
    std::cout << "W is in the word and in the correct spot.\n\n";
    
    std::cout << " ---  ---  ---  ---  --- \n";
    std::cout << "| P || \033[1;33mI\033[0m || L || L || S |\n";
    std::cout << " ---  ---  ---  ---  ---\n";
    std::cout << "I is in the word but in the wrong spot.\n\n";

    std::cout << " ---  ---  ---  ---  ---\n";
    std::cout << "| V || A || G || \033[1;37mU\033[0m || E |\n";
    std::cout << " ---  ---  ---  ---  ---\n";
    std::cout << "U is not in the word in any spot.\n\n";

    std::cout << "Press [enter] to continue";
}



#endif 
