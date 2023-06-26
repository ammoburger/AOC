#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
void print(T &vecOfElements, std::string delimeter = ",")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
}

template <typename T>
bool columnIsZeroDominant(T &binVec, int column)
{
    int zeroCount = 0;
    for (int i = 0; i < binVec.size(); i++)
    {
        if (binVec[i][column] == 0)
        {
            zeroCount++;
        }

        if (zeroCount > binVec.size() / 2)
        {
            return true;
        }
    }
    return false;
}

int charInt(char c)
{
    return (c == '0') ? 0 : 1;
}

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    vector<vector<int>> queenVec;
    vector<int> bugVec;

    int gamRate = 0, epsRate = 0, numColumns = 12;
    while (getline(inputFile, line))
    {
        bugVec.clear();
        for (int i = 0; i <= numColumns; i++)
        {
            if (bugVec.size() < numColumns)
            {
                bugVec.push_back(charInt(line[i]));
            }
        }
        queenVec.push_back(bugVec);
    }

        int zeroCount = 0;
    int binary = stoi("100011010011", 0, 2);

    for (int i = 0; i < numColumns; i++)
    {
        bool isZeroDominant = columnIsZeroDominant(queenVec, i);
        cout << isZeroDominant;
    }

    cout << endl;
    cout << binary << endl;
}

// 0 1 2 3 4 5 6 7 8 9  == Base 10
// 0 1 == Base 2
//
// 24 == 10 + 10 + 1 + 1 + 1 + 1
// 10 * 2 + (1 * 4)
// 148
// (10 * 10 * 1)

//     10
//   (2 * 1) + (1 * 0)
//    111
//    1000                          10 * 1  1 * 1
//   10*100  10*10   10*1 1     //   21

//   1   2    1
// (1*10^2) 2*(10^1) (1*10^0)
//  111
//  1000
