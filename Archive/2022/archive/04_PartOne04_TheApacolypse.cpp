#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
void printSet(T &numberset)
{
    for (auto &nums : numberset)
    {
        cout << nums << " ";
    }
}
template <typename T>
void print(T &vecOfElements, string delimeter = " ||||| ")
{
    for (auto elem : vecOfElements)
        cout << elem << delimeter;
    cout << endl;
}
void tokenize(string const &str, const char delim, vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) // stringstream, string, delim
    {
        out.push_back(s);
    }
}

int main()
{
    string newString;
    ifstream inFile;
    inFile.open("04input.txt");

    int lineCount = 0;

    vector<string> words;
    vector<string> leftString;
    vector<string> rightString;

    vector<int> lNums1; // LEFT
    vector<int> rNums1;
    //*             *//
    vector<int> lNums2;
    vector<int> rNums2; // RIGHT
    vector<string> tOut;
    const char delim = ',';

    set<int> numSet1;
    set<int> numSet2 = {6, 7, 8, 9, 10};

    while (getline(inFile, newString))
    {
        lineCount++;
        tokenize(newString, delim, tOut); // split based on commas
    }
    for (auto &newString : tOut)
    {
        words.push_back(newString); // put into vector, comma-less e.g. /4-6/3-8/...

        if (words.size() % 2 == 0) // sort based on even-numbered entries in "words" vector
        {
            rightString.push_back(newString); // sort in RIGHT column e.g. (3-8)
        }
        else
        {
            leftString.push_back(newString); // sort in LEFT column..
        }
    }

    for (int i = 0; i < leftString.size(); i++)
    {
        string lMod = leftString[i]; // initialize modified 'leftString'
        string del1 = "-";           // define delimiter

        string rTok = lMod.substr(lMod.find('-') + 1); // split number(token) on either side of '-'
        string lTok = lMod.substr(0, lMod.find(del1)); // ...

        lNums1.push_back(stoi(lTok)); // convert to 'int' and put it into vec of ints
        rNums1.push_back(stoi(rTok));
    }
    // cout << lineCount;
    //  print(lNums1);
    //  cout << lNums1.at(1);
}
