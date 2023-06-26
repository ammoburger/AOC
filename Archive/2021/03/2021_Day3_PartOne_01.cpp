#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
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

    vector<int> bitVec;

    while (getline(inputFile, line))
    {
        for (int i = 0; i <= numColumns; i++)
        {
            int bits = charInt(line[i]); //*  (line[0]) 0 = column(eg.  ->0<-1010)
            cout << bits;                //*  (line[1])0 = column(eg. 0 ->1<- 101)
        }
        cout << endl;
    }
}