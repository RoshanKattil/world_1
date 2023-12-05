#ifndef STAT_STUFF
#define STAT_STUFF

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>
#include <algorithm>

using namespace std;

void displayStatistics(const vector<std::string>& wins, const vector<std::string>& losses, const vector<std::string>& attempts, const vector<std::string>& words) 
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

#endif 
