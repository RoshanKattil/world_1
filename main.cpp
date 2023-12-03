#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Wordle
{
    public:
    
    const string allowedTxt = "allowed.txt";
    const string wordsTxt = "words.txt";
    
    string correctWord;
    string guessedWord;
    
    vector<char> green;
    vector<char> yellow;
    vector<char> grey;
    
    vector<string> allowed;
    vector<string> words;
    
    void loadAllowed() 
    {
        
        ifstream file(allowedTxt);
        if (file.is_open()) 
        {
            string word;
            while (getline(file, word)) 
            {
                allowed.push_back(word);
            }
            file.close();
        }
    }
    
    void randomWordGen()
    {
        int randomIndex = rand() % words.size();
        correctWord = words[randomIndex];
        
        cout << "the answer is " << correctWord << endl;
    }
    
    void loadWords() 
    {
        ifstream file(wordsTxt);
        if (file.is_open()) 
        {
            string word;
            while (getline(file, word)) 
            {
                words.push_back(word);
            }
            file.close();
        }
    }
    
    void setGuess()
    {
        cout << "enter in a word" << endl;
        getline(cin, guessedWord);
        
        while(!binary_search(allowed.begin(), allowed.end(), guessedWord))
        {
            
            cout << "\nThat's not a permitted word try again" << endl;
            getline(cin, guessedWord);
            
        }
    }
    
    
    
    bool solutionChecker()
    {
        for (size_t i = 0; i < correctWord.size(); ++i) 
        {
        if (guessedWord[i] == correctWord[i]) 
        {
            cout << "\033[1;32m" << guessedWord[i] << "\033[0m"; // Green
            green.push_back(guessedWord[i]);
        } 
        else if (find(correctWord.begin(), correctWord.end(), guessedWord[i]) != correctWord.end()) 
        {
            cout << "\033[1;33m" << guessedWord[i] << "\033[0m"; // Yellow
            yellow.push_back(guessedWord[i]);
        } 
        else {
            cout << "\033[1;37m" << guessedWord[i] << "\033[0m"; // Grey
            grey.push_back(guessedWord[i]);
        }
        }
        
        if(guessedWord == correctWord)
        {   
            cout << "\nyou win!" << endl;
            return true;
        }
        else
        {
            cout << "\ntry again" << endl;
            return false;
        }
    }
    
    
    
};

int main()
{
    
    int attempt_counter = 0;
    bool win_check = false;
    
    
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
        
        
        attempt_counter = 0;
        win_check = false;
        
        game.loadAllowed();
        game.loadWords();
        
        game.randomWordGen();
        
        while((attempt_counter < 6) && !win_check)
        {
            game.setGuess();
            attempt_counter++;
            win_check = game.solutionChecker();
        }
        
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
