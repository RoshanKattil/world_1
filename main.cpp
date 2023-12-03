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
    
    string randomWordGen()
    {
        int randomIndex = rand() % words.size();
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
            //cout << "\ntry again" << endl;
            return false;
        }
    }
    
    
    
};


void writeToTxt(vector<string> &stuff, string fileName)
{
    ofstream myfile(fileName, ofstream::app);

    if(myfile.is_open())
    {
        string str;
        for(int i = 0; i < stuff.size(); i++)
        {
            str = stuff[i];
            myfile<<str<< endl;
        }
        myfile.close();
    }
}

bool clearFile(string fileName)
{

  bool isCleared = false;
  int length;

  //takes in file name and clears the file
  ofstream myfile(fileName);
  myfile.close();

  //check if succsesful if yes then return true
  ifstream is;
  is.open (fileName.c_str(), ios::binary);
  is.seekg (0, ios::end);
  length = is.tellg();

  // check if number of charachters in file is 0 then 
  if (length == 0)
  {
    isCleared = true;
  }

  return isCleared;
  
}

vector<string> loadTxt(string fileName) 
{
    
    string x;
    vector<string> y;
    ifstream file(fileName);
    if (file.is_open()) 
    {
        string x;
        while (getline(file, x)) 
        {
            y.push_back(x);
        }
        file.close();
    }
    
    return y;
}

void displayStatistics(const std::vector<std::string>& wins, const std::vector<std::string>& losses, const std::vector<std::string>& attempts, const std::vector<std::string>& words) 
{
    
    int timesPlayed = wins.size();
    double totalAttempts = 0;
    double winCount = 0;
    int currentStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < timesPlayed; ++i) 
    {
        totalAttempts += stoi(attempts[i]);
        winCount += (wins[i] == "Yes") ? 1 : 0;
        
        if (wins[i] == "Yes") 
        {
            currentStreak++;
            longestStreak = max(longestStreak, currentStreak);
        } 
        else 
        {
            currentStreak = 0;
        }
    }

    // Display Statistics Summary
    std::cout << "==========================\n";
    std::cout << "    STATISTICS SUMMARY\n";
    std::cout << "==========================\n";
    std::cout << "Times Played:         " << timesPlayed << "\n";
    std::cout << "Average Attempts:     " << (timesPlayed > 0 ? totalAttempts / timesPlayed : 0) << "\n";
    std::cout << "Win Percentage:       " << fixed << setprecision(1) << (timesPlayed > 0 ? (winCount / timesPlayed) * 100 : 0) << "%\n";
    std::cout << "Current Streak:       " << currentStreak << "\n";
    std::cout << "Longest Streak:       " << longestStreak << "\n\n";
    std::cout << "--------------------------\n";
    std::cout << "WORD     ATTEMPTS      WIN\n";
    std::cout << "--------------------------\n";

    for (int i = 0; i < timesPlayed; ++i) 
    {
        std::cout << setw(8) << words[i] << setw(8) << attempts[i] << setw(8) << wins[i] << "\n";
    }

    cout << "\nPress [enter] to continue";
}


int main()
{
    
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
        
    }
    else if(option == "2")
    {
        cout << "How to play" << endl;
    }
    else if(option == "3")
    {
        cout << "Statistics Summary" << endl;
        displayStatistics(wins, losses, attempt_list, word_list);
        
        //change to wait for enter
        cin >> blank_space;
        
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
        
        writeToTxt(wins, "wins.txt");
        writeToTxt(losses, "losses.txt");
        writeToTxt(attempt_list, "attempt_list.txt");
        writeToTxt(word_list, "word_list.txt");
        
        break;
    }
    }
    
    
    
    while(option != "5");
    
    
    
    
    
    return 0;
}
