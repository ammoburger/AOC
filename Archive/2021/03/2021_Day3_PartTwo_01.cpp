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
vector<int> columnVec;
vector<int> rowVec;
vector<vector<int>> columnQueen;
vector<vector<int>> rowQueen;

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    int gamRate = 0, epsRate = 0;
    int totalLines = 12, totalColumns = 5; //* USER INPUT *//

    while (getline(inputFile, line))
    {
        for (int i = 0; i < totalColumns; i++) //? for every char in string e.g. '10010' = 5
        {
            columnVec.push_back(char2Int(getRowNumber(line, i))); //? convert char to int and push it into vector for length of .txt (e.g. 300 lines)
                                                                  //? if i=0* then first entry in row (e.g. 0*0100, i=1(00*100), i=2(001*00)..)
            if (columnVec.size() == totalColumns)
            {
                columnQueen.push_back(columnVec);
                columnVec.clear(); //? use an empty vector for each line
            }
        }
    }

    // for (int i = 0; i < totalLines; i++) //?  [A]-Row-numLines [B]-Column-maxColumns
    // {
    // }
}
//? auto(detect element (columnVector) / columnQueen(size of vector the range of the loop, e.g. 12)

//? for every column, iterate through the size of 'line'  e.g. 5 (01001) 12 times (01001)
//?                                                                               (10101)...