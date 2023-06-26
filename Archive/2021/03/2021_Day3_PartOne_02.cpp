#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
template <typename T>
void print(T &vecOfElements, std::string delimeter = ",")
{
    for (auto elem : vecOfElements)

        std::cout << elem << delimeter;
}
bool isZero(int num)
{
    if (num = 0)
    {
        return true;
    }
    return false;
}
int charInt(char c)
{
    if (c == '0')
    {
        return 0;
    }
    return 1;
}
int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_03_input.txt");

    int gamRate = 0, epsRate = 0, numColumns = 4;

    vector<vector<int>> queenVec;
    vector<int> bugVec;

    while (getline(inputFile, line))
    {
        bugVec.clear();
        for (int i = 0; i <= numColumns; i++)
        {
            if (bugVec.size() <= numColumns)
            {
                bugVec.push_back(charInt(line[i]));
            }
        }
        queenVec.push_back(bugVec);
    }

    for (int i = 0; i < queenVec.size(); i++)
    {
        int tally = 0;
        for (int j = 0; j < numColumns; j++)
        {
            // cout << queenVec[i][j];
            for (auto nm : queenVec)
            {
                if (isZero(nm.at(j)))
                {
                    cout << "poop";
                }
            }
        }
        cout << endl;
    }
}

//?     (line[0]) 0 = column(eg.  ->0<-1010)   // BUG
//?     (line[1])0 = column(eg. 0 ->1<- 101)   // VECTOR

//?    queenVec[0][1] =  0->1<-0               //QUEEN
//?            [1][2] =  1  0->1<-             //VECTOR