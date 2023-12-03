#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

class Wordle
{
    public:
    
    string correctWord = "games";
    string guessedWord;
    
    int green = 0;
    int yellow = 0;
    int grey = 0;
    
    void setGuess()
    {
        cout << "enter in a word" << endl;
        getline(cin, guessedWord);
        
    }
    
    void checkColors()
    {
        
        cout << "green: " << green;
        cout << "yellow: " << yellow;
        cout << "grey: " << grey;
        
    }
    
    bool solutionChecker()
    {
        
        for (size_t i = 0; i < correctWord.size(); ++i) 
        {
        if (guessedWord[i] == correctWord[i]) 
        {
            cout << "\033[1;32m" << guessedWord[i] << "\033[0m"; // Green
            green++;
        } 
        else if (find(correctWord.begin(), correctWord.end(), guessedWord[i]) != correctWord.end()) 
        {
            cout << "\033[1;33m" << guessedWord[i] << "\033[0m"; // Yellow
            yellow++;
        } 
        else {
            cout << "\033[1;37m" << guessedWord[i] << "\033[0m"; // Grey
            grey++;
        }
        }
        
        
        
    }
    
    
    
};

int main()
{
    
    
    cout << "=========================" << endl;
    cout << "WELCOME TO WORDLE" << endl;
    cout << "=========================" << endl;
    cout << endl;

    cout << "1. Play Wordle" << endl;
    cout << "2. How to Play" << endl;
    cout << "3. Statistics Summary" << endl;
    cout << "4. Reset Statistics" << endl;
    cout << "5. Exit" << endl;
    cout << endl;


    cout << "Select an option:" << endl;
    
    string option;
    getline(cin, option); 
    
    if(option == "1")
    {
        cout << "play Wordle" << endl;
        Wordle game;
        
        game.setGuess();
        
        game.solutionChecker();
        
        game.checkColors();
        
        
    }
    else if(option == "2")
    {
        cout << "How to play" << endl;
    }
    else if(option == "3")
    {
        cout << "Statistics Summary" << endl;
    }
    else if(option == "4")
    {
        cout << "Reset Statistics" << endl;
    }
    else if(option == "5")
    {
        cout << "Exit" << endl;
    }
    
    
    
    
    
    
    return 0;
}
