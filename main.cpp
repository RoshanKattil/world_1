#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

class Wordle
{
    
    string correctWord = "games";
    string guessedWord = "books";
    
    int green = 0;
    int yellow = 0
    int grey = 0;
    
    void setGuess()
    {
        
        string option;
        getline(cin, option);
        
    }
    
    bool solutionChecker()
    {
        
        if(correctWord == guessedWord)
        {
            
            green = 5;
            return true;
        }
        else
        {
            
            for(int i = 0; i < 5; i++)
            {
            
                for(int n = 0; n < 5; n++)
                {
                    
                    if((i == n) && (correctWord[i] == correctWord(n)))
                    {
                        
                        green++;
                        
                    }
                    else if(!(i == n) && (correctWord[i] == correctWord(n)))
                    {
                        
                        yellow++;
                        
                    }
                    else
                    {
                        
                        grey++;
                        
                    }
                    
                }
            
            }
            
            return false;
        }
        
        
        
    }
    
    
    
}

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
