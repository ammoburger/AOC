#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
bool isGreater(int oldDepth, int newDepth)
{
    if (newDepth > oldDepth && oldDepth != 0)
    {
        return true;
    }
    return false;
}
int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_01_input.txt");

    int depth = 0, finalScore = 0;
    vector<int> dVec;

    while (getline(inputFile, line))
    {
        depth = stoi(line);
        dVec.push_back(depth);
    }

    for (int i = 1; i < dVec.size(); i++)
    {

        int newD = dVec.at(i);
        int oldD = dVec.at(i - 1);

        //(return newD > oldD)

        // if (isGreater(oldD, newD))
        // {
        //     finalScore++;
        // }
    }
    cout << finalScore;
}
