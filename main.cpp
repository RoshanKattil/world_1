#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>
#include <algorithm>
#include <random>

#include "dataMod.h"
#include "showStats.h"
#include "howToPlay.h"


#include <termios.h>
#include <unistd.h>


using namespace std;

class Wordle
{
    public:
    
    const string allowedTxt = "allowed.txt";
    const string wordsTxt = "words.txt";
    
    string correctWord;
    string guessedWord;
    
    vector<string> green;
    vector<string> yellow;
    vector<string> grey;
    
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
    
    string randomWordGen()
    {

        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator
        uniform_int_distribution<> distr(0, words.size());
        int randomIndex = distr(gen);

        //int randomIndex = rand() % words.size();
        correctWord = words[randomIndex];
        
        cout << "the answer is " << correctWord << endl;
        
        return correctWord;
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
        //cout << "enter in a word" << endl;
        getline(cin, guessedWord);
        
        while(!binary_search(allowed.begin(), allowed.end(), guessedWord) && !binary_search(words.begin(), words.end(), guessedWord))
        {
            
            cout << "\nThat's not a permitted word try again" << endl;
            getline(cin, guessedWord);
            
        }
    }
    
    
    
    bool solutionChecker()
    {
        string tempString;
        for (size_t i = 0; i < correctWord.size(); ++i) 
        {
            if (guessedWord[i] == correctWord[i]) 
            {
                cout << "\033[1;32m" << guessedWord[i] << "\033[0m"; // Green
                tempString += guessedWord[i];
                green.push_back(tempString);
                tempString = "";
            } 
            else if (find(correctWord.begin(), correctWord.end(), guessedWord[i]) != correctWord.end()) 
            {
                cout << "\033[1;33m" << guessedWord[i] << "\033[0m"; // Yellow
                tempString += guessedWord[i];
                yellow.push_back(tempString);
                tempString = "";
            } 
            else {
                cout << "\033[1;37m" << guessedWord[i] << "\033[0m"; // Grey
                tempString += guessedWord[i];
                grey.push_back(tempString);
                tempString = "";
            }

            cout << " | ";
        }

        cout << "\n";
        
        
        writeToTxt(green, "green.txt");
        writeToTxt(yellow, "yellow.txt");
        writeToTxt(grey, "grey.txt");
        
        if(guessedWord == correctWord)
        {   
            cout << "\nyou win!" << endl;
            return true;
        }
        else
        {
            //cout << "\ntry again" << endl;
            return false;
        }
    }
    
    
    
};


int main()
{
    
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int attempt_counter = 0;
    bool win_check = false;
    string option;
    string blank_space;
    
    vector<string> attempt_list;
    vector<string> wins;
    vector<string> losses;
    vector<string> word_list;
    
    
    
    
    
    
    do{
        
        //cout << wins.size() << " wins and losses " << losses.size()  << attempt_list.size()<< endl;;
        
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
    
    
    getline(cin, option);
    
    if(option == "1")
    {
        cout << "play Wordle" << endl;
        Wordle game;
        
        
        attempt_counter = 0;
        win_check = false;
        
        game.loadAllowed();
        game.loadWords();
        
        word_list.push_back(game.randomWordGen());
        
        while((attempt_counter < 6) && !win_check)
        {
            game.setGuess();
            attempt_counter++;
            win_check = game.solutionChecker();
            if(win_check)
            {
                wins.push_back("Yes");
                losses.push_back("No");
                attempt_list.push_back(to_string(attempt_counter));
            }
        }
        
        if(!win_check)
        {
            wins.push_back("No");
            losses.push_back("Yes");
            //cout << "adding a loss" << endl;
            attempt_list.push_back(to_string(attempt_counter));
            
            
        }
        
        cout << "Press [enter] to continue" << endl;
        getline(cin, blank_space);


        clearFile("green.txt");
        clearFile("yellow.txt");
        clearFile("grey.txt");

        writeToTxt(wins, "wins.txt");
        writeToTxt(losses, "losses.txt");
        writeToTxt(attempt_list, "attempt_list.txt");
        writeToTxt(word_list, "word_list.txt");

        wins.clear();
        losses.clear();
        attempt_list.clear();
        word_list.clear();
        
    }
    else if(option == "2")
    {
        cout << "How to play" << endl;
        displayHowToPlay();
        getline(cin, blank_space);
    }
    else if(option == "3")
    {
        cout << "Statistics Summary" << endl;
        vector<string> wins1 = loadTxt("wins.txt");
        vector<string> losses1 = loadTxt("losses.txt");
        vector<string> attempt_list1 = loadTxt("attempt_list.txt");
        vector<string> word_list1 = loadTxt("word_list.txt");
        displayStatistics(wins1, losses1, attempt_list1, word_list1);
        
        //change to wait for enter
        getline(cin, blank_space);
        
    }
    else if(option == "4")
    {
        cout << "Reset Statistics" << endl;
        clearFile("wins.txt");
        clearFile("losses.txt");
        clearFile("attempt_list.txt");
        clearFile("word_list.txt");
        
        
    }
    else if(option == "5")
    {
        cout << "Exit" << endl;
        
        
        
        break;
    }
    }
    
    
    
    while(option != "5");
    
    
    
    
    
    return 0;
}
