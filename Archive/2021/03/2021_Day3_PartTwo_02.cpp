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

int char2Int(char convert)
{
    return convert - '0';
}

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    int gamRate = 0, epsRate = 0;
    int totalLines = 12, totalColumns = 5; //? USER INPUT //

    while (getline(inputFile, line))
    {
        stringVec.push_back(line); // strings to vector
    }
    /**
     * Stitch all the strings together
     * For length of stitch, append new string
     *
     *
     *
     */
    /***/
    string stitch;
    for (int i = 0; i < stringVec.size(); i++)
    {
        stitch.append(stringVec[i]);
    }

    string frankenStein;

    for (int i = 0; i < stitch.size(); i++)
    {
        char electricity = stitch[i];
        frankenStein += electricity;

        if (frankenStein.size() == totalLines)
        {
            columnVec.push_back(stoi(frankenStein));
        }
    }

    // cout << frankenStein;
    print(columnVec);
}
