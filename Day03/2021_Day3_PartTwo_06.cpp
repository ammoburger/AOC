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
void print(T &vecOfElements, string delimeter = ",")
{
    for (auto elem : vecOfElements)
        cout << elem << delimeter << endl;
}

bool getOneMajority(vector<string> lv, int pos)
{
    int counter = 0;
    for (int i = 0; i < lv.size(); i++)
    {
        string mod = lv[i];
        if (mod[pos] == '1')
        {
            counter++;
            if (counter >= lv.size() / 2)
            {
                return true;
            }
        }
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
    string stitch;

    inputFile.open("2021_03_input.txt");

    int gamRate = 0,
        epsRate = 0;

    int totalColumns = 5;
    int totalRows = 12;

    while (getline(inputFile, line, '_'))
    {

        split(lineVec, line, is_any_of("\n"));
    }
    vector<string> finalVec;

    for (int i = 0; i < totalColumns; i++)
    {
        /* code */
    }

    if (getOneMajority(lineVec, 0)) //? vector<string>, position
    {
        finalVec = editVector(lineVec, 0, '1'); //?vec, position, 'char' to remove
    }
    print(finalVec);
}
