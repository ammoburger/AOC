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
    // cout << plus;
    string poop = "";
    char c = '-';
    c = str[num + plus];
    // cout << c;
    poop.push_back(c);

    return poop;
    // string f = s + plus;
}
//*****************************************************

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    string stitch;

    int gamRate = 0,
        epsRate = 0;

    int totalColumns = 5;
    int totalRows = 12;

    while (getline(inputFile, line))
    {
        stitch.append(line);
    }
    int counter = 0;
    for (int i = 0; i < stitch.size(); i++)
    {
        if (i % 5 == 0)
        {
            // char c = stitch[i + 1];

            string fart = frankenString(stitch, i, 0);
            string bitch = frankenString(stitch, i, 1);
            string ass = frankenString(stitch, i, 2);
            string cunt = frankenString(stitch, i, 3);
            string scrotum = frankenString(stitch, i, 4);

            cout << fart;
            cout << bitch;
            cout << ass;
            cout << cunt;
            cout << scrotum;

            cout << endl;

            // newStitch.push_back(c);

            // cout << c;
            // if (newStitch.size() == 12)
            // {
            //     newStitch.clear();
            //     counter++;
            // }
        }
    }
    // cout << newStitch;
    return 0;
}
