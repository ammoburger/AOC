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

int main()
{
    string line;
    ifstream inputFile;

    vector<string> lineVec;

    string oxygen = "oxygen", co2 = "co2";
    inputFile.open("2021_03_input.txt");

    while (getline(inputFile, line))
    {
        cout << line << endl;
    }
}
