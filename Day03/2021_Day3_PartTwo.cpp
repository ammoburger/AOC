#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "FunctionLibrary.h"

using namespace std;

template <typename T>
void print(T &vecOfElements, std::string delimeter = ",")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter << endl;
}

bool frankenString(vector<string> lVec, int totRows, int subStart)
{
    int counter = 0;
    bool oneMajority = false;

    for (int i = 0; i < lVec.size(); i++)
    {

        string newString = lVec.at(i);                               // grab string from vector (e.g. 00100)
        string subString = newString.substr(subStart, subStart + 1); // make substring (e.g. 0)

        if (subString[0] == '1') // if pos 0 in string has the char '1'
        {
            counter++;
        }
        if (counter >= totRows / 2) // counter of '0's is less than 6 (total rows)
        {
            oneMajority = true;
        }
        else
        {
            oneMajority = false;
        }
    }
    return oneMajority;
}
//*****************************************************
vector<string> stripString(vector<string> lVec, bool isOneDom)
{
    vector<string> newLineVec = lVec;

    for (int i = 0; i < newLineVec.size(); i++)
    {

        string baseString = newLineVec.at(i);
        if (isOneDom) // if pos 0 in string has the char '1'
        {
            if (baseString[0] == '0') // pos 0 has '0' and //?'1' is DOMINANT
            {

                newLineVec.erase(newLineVec.begin() + i);
            }
        }
    }
    // cout << newLineVec.size();
    return newLineVec;
}

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    vector<string> lineVec;

    int gamRate = 0, epsRate = 0;

    int totalColumns = 5;
    int totalRows = 12;

    while (getline(inputFile, line))
    {
        lineVec.push_back(line);
    }
    bool bOne = false;
    vector<string> newLineVec;

    for (int i = 0; i < totalRows; i++)
    {
        if (frankenString(lineVec, totalRows, i)) // if One is Dominant
        {
            bool bOne = true;
            cout << "true";
            newLineVec = stripString(lineVec, bOne);

            // PRINT
            // cout << "Row -> " << i << " = true";
            // cout << endl;
        }

        // print(newLineVec);
    }

    return 0;
}
