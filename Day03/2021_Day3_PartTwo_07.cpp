#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include "FunctionLibrary.h"

using namespace std;
using namespace boost;

template <typename T>
void print(T &vecOfElements, string delimeter = " ")
{
    for (auto elem : vecOfElements)
        cout << elem << delimeter << endl;
}

bool getOneMajority(vector<string> lv, int pos)
{
    int counter = 0;
    int zeroCounter = 0;
    for (int i = 0; i < lv.size(); i++)
    {
        string mod = lv[i];
        if (mod[pos] == '1')
        {
            counter++;
        }
        else if (mod[pos] == '0')
        {
            zeroCounter++;
        }
    }
    if (counter >= lv.size() / 2 && counter > zeroCounter || zeroCounter == 1 && counter == 1)
    {
        return true;
    }

    return false;
}

vector<string> editVector(vector<string> lv, int pos, char removal)
{
    vector<string> vs;

    for (int i = 0; i < lv.size(); i++)
    {
        string mod = lv[i];
        if (mod[pos] == removal)
        {
            vs.push_back(lv[i]);
        }
    }
    return vs;
}

//*****************************************************
int main()
{
    string line;
    ifstream inputFile;

    vector<string> lineVec;
    vector<vector<string>> lineQueenVec;
    string stitch;

    inputFile.open("2021_03_input.txt");

    int gamRate = 0,
        epsRate = 0;

    int totalColumns = 5;
    int totalRows = 12;

    while (getline(inputFile, line))
    {
        split(lineVec, line, is_any_of("\n"));
    }

    vector<string> finalVec;
    int pos = 0;

    for (int i = 0; i < totalColumns; i++)
    {
        pos++;
        if (getOneMajority(lineVec, pos)) //? vector<string>, position
        {

            finalVec = editVector(lineVec, pos, '1'); //?vec, position, 'char' to remove
        }
        else
        {
            finalVec = editVector(lineVec, pos, '0'); //?vec, position, 'char' to remove
        }
    }

    print(finalVec);
}
