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
auto above(int threshold)
{
    // This captures a copy of threshold
    return [=](int value)
    {
        return value >= threshold;
    };
};
void frankenString(string str, int colNum)
{
    string frank = "";
    frank.push_back(str[colNum]);

    // cout << i << endl;
    // frank.push_back(str[10]);
    cout << frank;
    // cout << str[i];

    // cout << str;
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

    while (getline(inputFile, line))
    {
        lineVec.push_back(line);

        stitch.append(line.substr(1, 2));
    }
    // cout << stitch << endl;
    int x = (count(stitch.begin(), stitch.end(), '1') >= stitch.size() / 2);
    cout << x;
    if (count(stitch.begin(), stitch.end(), '1') >= stitch.size() / 2) //? one is dominant
    {
        for (int i = 0; i <= stitch.size(); i++)
        {
            if (stitch[i] == '1')
            {
                // cout << lineVec[i] << endl;
            }
        }
    }
    else
    {
    }
    //  print(lineVec);

    // for (int i = 0; i < stitch.size(); i++)
    // {

    //     for (int j = 0; j < totalColumns; j++)
    //     {
    //         frankenString(stitch, j);
    //     }
    // }
}
