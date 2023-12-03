#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

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
