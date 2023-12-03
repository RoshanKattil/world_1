#ifndef DATA_STUFF
#define DATA_STUFF

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>
#include <algorithm>

using namespace std;

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

bool clearFile(string fileName)
{

  bool isCleared = false;
  int length;

  //takes in file name and clears the file
  ofstream myfile(fileName, ofstream::out | ofstream::trunc);
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


#endif 
