#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <boost/lambda/lambda.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

template <typename T>
void print(T &vecOfElements, string delimeter = ",")
{
    for (auto elem : vecOfElements)
        cout << elem << delimeter << endl;
}

int main()
{

    ifstream inputFile;
    inputFile.open("2021_04_input.txt");

    string line;
    string splitLine;
    string splitLineDos;

    int bingoStringWidth = 14; // width of bingo board string

    vector<string> splitDrawNumStr;
    vector<string> splitBingoNumStr;

    vector<int> bingoNums;
    set<int> drawNums;

    while (getline(inputFile, line))
    {

        if (line.size() != bingoStringWidth)
        {
            split(splitDrawNumStr, splitLine.append(line), is_any_of(","));
            for (auto drawNumStr : splitDrawNumStr)
            {                                      //? This runs a few times but theyre all unique. could make it better
                drawNums.insert(stoi(drawNumStr)); // convert string to ints
            }
        }
        else
        {
            // split(splitBingoNumStr, splitLineDos.append(line), lambda_1 == ':');
        }
    }
    for (auto bNums : splitBingoNumStr)
    {

        // string justNums = bNums.substr(0, bNums.find_first_of(','));
        // cout << justNums << endl;
        //  cout << bNums;
        bingoNums.push_back(stoi(bNums));
        // cout << bNums << endl;
    }
    // cout << "poop";
    print(bingoNums);
}
