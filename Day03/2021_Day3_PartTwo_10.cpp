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

char processInfo(vector<string> lVec, int pos, string data)
{
    int countOne = 0;
    int countZero = 0;
    char one = '1';
    char zero = '0';

    for (int i = 0; i < lVec.size(); i++)
    {
        string mod = lVec[i]; // e.g. 01011
        if (mod[pos] == '1')  // e.g. 01[1]00
        {
            countOne++;
        }
        else if (mod[pos] == '0')
        {
            countZero++;
        }
    }
    // cout << "Zeros = " << countZero
    //      << " Ones = " << countOne << endl;

    if (data == "oxygen") //? find MOST common value
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
    //? CO2
    if (data == "co2") //? find LEAST common value
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

vector<string> editVector(vector<string> lVec, int pos, char numToRemove)
{
    vector<string> vs;
    for (int i = 0; i < lVec.size(); i++)
    {
        string mod = lVec[i];
        if (mod[pos] == numToRemove)
        {
            vs.push_back(lVec[i]);
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
    vector<string> finalVec;

    string oxygen = "oxygen", co2 = "co2";
    inputFile.open("2021_03_input.txt");

    int gamRate = 0,
        epsRate = 0;

    while (getline(inputFile, line, '_'))
    {
        split(lineVec, line, is_any_of("\n"));
    }

    int pos = 0;
    int binaryNum = 0;
    for (int i = 0; i < 12; i++)
    {
        vector<string> inVec;
        inVec = lineVec;
        if (i > 0)
        {
            inVec = finalVec;
        }
        if (inVec.size() < 2)
        {
            break;
        }
        /*==================================================================================================*/
        /*==================================================================================================*/

        //*
        // cout << inVec.size() << endl;
        binaryNum = processInfo(inVec, pos, co2);

        //? vector<string>, position, datatype
        finalVec = editVector(inVec, pos, binaryNum); //?vec, position, 'char' to remove

        pos++;

        //*
        //*
        /*==================================================================================================*/
        /*==================================================================================================*/
        //
        //
        /*==================================================================================================*/
        /*==================================================================================================*/

        //*

        // if (getOneMajority(inVec, pos)) //? vector<string>, position
        // {
        //     finalVec = editVector(inVec, pos, '1'); //?vec, position, 'char' to remove
        // }
        // else
        // {
        //     finalVec = editVector(inVec, pos, '0'); //?vec, position, 'char' to remove
        // }
        // pos++;
        //*
        //*
        /*==================================================================================================*/
        /*==================================================================================================*/
    }
    print(finalVec);
}
