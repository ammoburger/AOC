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

string frankenString(string str, int num, int loop)
{

    string blank = "";
    char c = '-';
    c = str[num + loop];
    blank.push_back(c);

    return blank;
}
//*****************************************************
int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");
    vector<string> stitchVec, lineVec;
    string stitch, glued;

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
            for (int j = 0; j < totalColumns; j++)
            {
                string cut = "";
                cut.append(frankenString(stitch, i, j));
                glued.append(cut);
                if (glued.size() >= totalRows)
                {
                    // stitchVec.push_back(glued);
                    // glued.clear();
                }
            }
        }
    }
    // cout << stitchVec[0];

    // print(stitchVec);

    // print(stitchVec);
    // return 0;
}
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