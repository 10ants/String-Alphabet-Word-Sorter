#include <sstream> 
#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;

//Recursive
string Recurse(list<string> some)
{
    if(some.size() == 0)
    {
        return "";
    }
    
    string firstWord = some.front();
    some.pop_front();
    list<string> beforeList;
    list<string> afterList;
    //Look at first word
    for(string one: some)//Make list of before and after
     {    if (one < firstWord)
            beforeList.push_back(one);
        else 
            afterList.push_back(one);
     }
    //Return before, return the word, return after
   // Recurse(beforeList) + firstWord + Recurse(afterList);
    return Recurse(beforeList) + firstWord + " " + Recurse(afterList);
}

//Driver
string AdamDriver ( list<string> words)
{
    ///Look at recurse
    
    return Recurse (words);
}

int main()
{
    //Print everything before the first word.
    //Then print the firstword.
    //Then print everything after it.
    string whole;
    cout<< " Enter your sentence monkey man:"<< endl; //Read string from user
    getline(cin, whole);

    istringstream ss(whole);
    list<string> words;
    string single; 
    while (ss >> single) 
    {
        words.push_back(single);
    }
  
   cout<< AdamDriver(words);
    
    return 0;
}
