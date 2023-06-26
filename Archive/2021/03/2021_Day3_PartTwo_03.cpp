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
int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    int gamRate = 0, epsRate = 0, totalColumns = 0;
    int totalRows = 12; //! USER INPUT

    vector<vector<int>> queenVec;
    vector<int> bugVec;
    //?
    vector<int> columnVec;
    vector<vector<int>> columnQueenVec;

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

    for (auto bug : queenVec)
    {
        for (int i = 0; i < totalColumns; i++)
        {
            columnVec.push_back(bug[i]);
            if (columnVec.size() == totalColumns)
            {
                columnQueenVec.push_back(columnVec);
                columnVec.clear();
            }
        }
    }

    for (int k = 0; k < columnQueenVec.size(); k++)
    {
        for (int i = 0; i < totalRows; i++)
        {
            cout << columnQueenVec[i][1];
        }
        cout << endl;
    }

    //? [A]<-ROW  (0)[B]<-COLUMN
    //? (00100)   (1)
}

/**
 *TODO - gather lines in vec, covert to ints
 *TODO - convert rows to columns
 *
 *
 *
 */
