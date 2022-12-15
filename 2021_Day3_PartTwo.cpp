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

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    int gamRate = 0, epsRate = 0, totalColumns = 0, totalRows = 12;

    int rowSwitch = 0;
    vector<string> lineVec;
    vector<vector<string>> columnVec;

    while (getline(inputFile, line))
    {
        int totalColumns = line.size(); //? total lines from input
    }
    string modString = line.substr(0, 1);

    if (lineVec.size() >= totalRows)
    {
        columnVec.push_back(lineVec);
        lineVec.clear();
    }
    cout << addNumbers(10, 15);
}
