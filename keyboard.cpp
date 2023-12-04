#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include  <bits/stdc++.h>
#include <algorithm>

#include "/home/me/workspace/assignments/programming-project/exercise-1/wordle/dataMod.h"

using namespace std;

bool look_for(vector<string> x, string y)
{

        for( string i : x)
        {

            if(i == y)
            {
                return true;
            }

        }
        
        return false;

}

void displayKeyboardViewer() {
    cout << "=============================================\n";
    cout << "           KEYBOARD VIEWER\n";
    cout << "=============================================\n\n";
    
    vector<string> green = loadTxt("/home/me/workspace/assignments/programming-project/exercise-1/wordle/green.txt");
    vector<string> yellow = loadTxt("/home/me/workspace/assignments/programming-project/exercise-1/wordle/yellow.txt");
    vector<string> grey = loadTxt("/home/me/workspace/assignments/programming-project/exercise-1/wordle/grey.txt");
    
    string tempString = "";

    
    
    
    for (char c = 'a'; c <= 'z'; ++c) 
    {
        tempString += c;
        
        if (look_for(green, tempString)) {
            cout << "\033[1;32m" << setw(3) << c << "\033[0m"; // Green
        }
        else if(look_for(yellow, tempString))
        {
            
            cout << "\033[1;33m" << setw(3) << c << "\033[0m"; // Yellow
            
        }
        else if(look_for(grey, tempString))
        {
            cout << "\033[1;37m" << setw(3) << c << "\033[0m"; // Gray
        }
        else
        {
            cout << setw(3) << c; // Gray
        }
        

        // Add a newline every 10 characters for better readability
        if ((c - 'A' + 1) % 10 == 0) {
            std::cout << std::endl;
        }
        
        tempString = "";
    }

    std::cout << "\n\nPress [enter] to exit the Keyboard Viewer";
}

int main() {
    displayKeyboardViewer();

    cin.ignore();
    cin.get();

    return 0;
}
