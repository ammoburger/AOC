#include <iostream>
#include <string>
#include <fstream>

using namespace std;
bool checkUnique(string str)
{
    for (int x = 0; x < str.size(); x++) // size of this substr == checkSize (4)
    {
        for (int j = x + 1; j < str.size(); j++)
        {
            if (str[x] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ifstream inputFile;
    inputFile.open("06input.txt");
    string line;

    int checkSize = 14;

    while (getline(inputFile, line))
    {
        for (int i = 0; i <= line.size(); i++)
        {
            if (checkUnique(line.substr(i, checkSize)))
            {
                cout << i + checkSize;
                return 0;
            }
        }
    }
}