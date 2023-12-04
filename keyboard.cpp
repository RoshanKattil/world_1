#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include  <bits/stdc++.h>
#include <algorithm>

#include "assignments/programming-project/exercise-1/wordle/dataMod.h"

using namespace std;

void displayKeyboardViewer() {
    cout << "=============================================\n";
    cout << "           KEYBOARD VIEWER\n";
    cout << "=============================================\n\n";
    
    vector<string> green = loadTxt("assignments/programming-project/exercise-1/wordle/green.txt");
    vector<string> yellow = loadTxt("assignments/programming-project/exercise-1/wordle/yellow.txt");
    vector<string> grey = loadTxt("assignments/programming-project/exercise-1/wordle/grey.txt");
    
    string tempString = "";
    
    
    for (char c = 'A'; c <= 'Z'; ++c) 
    {
        tempString += c;
        
        if (green.find(tempString)) {
            cout << "\033[1;32m" << setw(3) << c << "\033[0m"; // Green
        }
        else if(yellow.find(tempString))
        {
            
            cout << "\033[1;33m" << setw(3) << c << "\033[0m"; // Yellow
            
        }
        else 
        {
            cout << "\033[1;37m" << setw(3) << c << "\033[0m"; // Gray
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
