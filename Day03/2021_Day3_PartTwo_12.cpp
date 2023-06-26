#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
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

char processInfo(vector<string> lines, int pos, string data)
{
    int countOne = 0;
    int countZero = 0;
    char one = '1';
    char zero = '0';

    for (int i = 0; i < lines.size(); i++)
    {
        string mod = lines[i]; // e.g. 01011
        if (mod[pos] == '1')   // e.g. 01[1]00
        {
            countOne++;
        }
        else if (mod[pos] == '0')
        {
            countZero++;
        }
    }

    if (data == "oxygen") // find MOST common value
    {
        if (countOne > countZero || countOne == countZero)
        {
            return one;
        }
        else
        {
            return zero;
        }
    }

    if (data == "co2") // find LEAST common value
    {
        if (countOne > countZero || countOne == countZero)
        {
            return zero;
        }
        else
        {
            return one;
        }
    }
    return 000;
}

vector<string> editVector(vector<string> lines, int pos, char numToKeep)
{
    vector<string> vs;
    for (int i = 0; i < lines.size(); i++)
    {
        string mod = lines[i];
        if (mod[pos] == numToKeep)
        {
            vs.push_back(lines[i]);
        }
    }
    return vs;
}

int main()
{
    string line;
    ifstream inputFile;

    vector<string> lines;

    string oxygen = "oxygen", co2 = "co2";
    inputFile.open("2021_03_input.txt");

    while (getline(inputFile, line, '_'))
    {
        split(lines, line, is_any_of("\n")); // tokenize string based on new line
    }

    for (int pos = 0; pos < 12 && lines.size() > 1; pos++)
    {
        //** GET INFO BASED ON DATA REQUEST e.g. OXYGEN/CO2
        //==================================================================================//
        // binaryNum = processInfo(inVec, pos, co2); // vector<string>, position, datatype
        // binaryNum = processInfo(inVec, pos, oxygen);
        //==================================================================================//

        //** TRIM THE VECTOR
        int binaryNum = processInfo(lines, pos, oxygen);
        lines = editVector(lines, pos, binaryNum);
    }
    print(lines);
}
