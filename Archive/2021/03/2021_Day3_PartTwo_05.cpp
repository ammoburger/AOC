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

int getRowNumber(string line, int rowNum)
{
    return line[rowNum];
}

void harvestQueen(vector<vector<int>> queen, int columnNum)
{
    for (auto bug : queen)
    {
        // cout << bug.at(0);
        if (bug.at(columnNum) == 1) // how many 0's/1's exist at pos 0 on the COLUMN
        {
            //* if (countOnes >= 12 / 2) //? if 1's are dominant
        }
    }
}
int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    int gamRate = 0, epsRate = 0, totalColumns = 0;
    int totalRows = 12; //? the number of lines in document

    vector<vector<int>> queenVec;
    vector<int> bugVec;

    while (getline(inputFile, line))
    {
        totalColumns = line.size();

        for (int i = 0; i < totalColumns; i++)
        {
            bugVec.push_back(char2Int(getRowNumber(line, i))); // convert to int.. put in vector
            if (bugVec.size() == totalColumns)
            {
                queenVec.push_back(bugVec);
                bugVec.clear();
            }
        }
    }

    for (int i = 0; i < totalColumns; i++) //? harvest every column
    {
        harvestQueen(queenVec, i);
    }
}

//? [A]<-ROW  (0)[B]<-COLUMN
//? (00100)   (1)

/**
 *TODO - gather lines in vec, covert to ints
 *TODO - convert rows to columns
 *TODO - remove/replace rows
 *TODO - reconstruct vector
 *
 */
