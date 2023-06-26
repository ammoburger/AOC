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
    int oneCounter = 0;
    int zeroCounter = 0;
    for (int i = 0; i < lv.size(); i++)
    {
        string mod = lv[i];
        if (mod[pos] == '1')
        {
            oneCounter++;
        }
        if (mod[pos] == '0')
        {
            zeroCounter++;
        }
    }
    if (oneCounter >= lv.size() / 2 && oneCounter > zeroCounter || zeroCounter == 1 && oneCounter == 1)
    {
        return true;
    }

    return false;
}
bool getOneMinority(vector<string> lv, int pos)
{
    int oneCounter = 0;
    int zeroCounter = 0;
    for (int i = 0; i < lv.size(); i++)
    {
        string mod = lv[i];
        if (mod[pos] == '1')
        {
            oneCounter++;
        }
        if (mod[pos] == '0')
        {
            zeroCounter++;
        }
    }
    if (oneCounter > lv.size() / 2 && oneCounter > zeroCounter || oneCounter == 1)
    {
        return false;
    }

    return true;
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

    inputFile.open("2021_03_input.txt");

    int gamRate = 0,
        epsRate = 0;

    while (getline(inputFile, line, '_'))
    {
        split(lineVec, line, is_any_of("\n"));
    }
    vector<string> finalVec;
    int pos = 0;

    for (int i = 0; i < 12; i++)
    {
        vector<string> inVec;
        inVec = lineVec;
        if (i > 0)
        {
            inVec = finalVec;
        }
        // cout << inVec.size();
        if (inVec.size() == 2)
        {
            break;
        }
        /*==================================================================================================*/
        /*==================================================================================================*/
        //*!CO2
        //*
        cout << inVec.size() << endl;
        if (getOneMinority(inVec, pos)) //? vector<string>, position
        {
            finalVec = editVector(inVec, pos, '1'); //?vec, position, 'char' to remove
        }
        else
        {
            finalVec = editVector(inVec, pos, '0'); //?vec, position, 'char' to remove
        }
        pos++;

        //*
        //*
        /*==================================================================================================*/
        /*==================================================================================================*/
        //
        //
        /*==================================================================================================*/
        /*==================================================================================================*/
        //*! OXYGEN RATING
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
