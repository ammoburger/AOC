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

string frankenString(string str, int num, int plus)
{

    string poop = "";
    char c = '-';

    c = str[num + plus];

    poop.push_back(c);

    return poop;
}

//*****************************************************

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");
    vector<string> stitchVec;
    vector<vector<string>> stitchQueenVec;
    vector<string> lineVec;

    string stitch;

    string cA;
    string cB;
    string cC;
    string cD;
    string cE;

    int gamRate = 0,
        epsRate = 0;

    int totalColumns = 5;
    int totalRows = 12;

    while (getline(inputFile, line))
    {
        lineVec.push_back(line);
        stitch.append(line);
    }
    int counter = 0;
    for (int i = 0; i < stitch.size(); i++)
    {
        if (i % 5 == 0)
        {

            cA.append(frankenString(stitch, i, 0));
            cB.append(frankenString(stitch, i, 1));
            cC.append(frankenString(stitch, i, 2));
            cD.append(frankenString(stitch, i, 3));
            cE.append(frankenString(stitch, i, 4));
        }
    }
    stitchVec.push_back(cA);
    stitchVec.push_back(cB);
    stitchVec.push_back(cC);
    stitchVec.push_back(cD);
    stitchVec.push_back(cE);

    //? see if i can remove all columns that start w zero
    // sort(lineVec.begin(), lineVec.end(), greater<string>());
    // if (count(cA.begin(), cA.end(), '1') > totalRows / 2)
    // {
    //     for (int i = 0; i < totalRows; i++) //? ONE IS DOMINANT!
    //     {
    //         if (cA[i] == '0')
    //         {
    //             sort(lineVec.begin(), lineVec.end(), greater<string>());
    //             lineVec.pop_back();
    //         }
    //     }
    // }

    print(lineVec);
    return 0;
}
