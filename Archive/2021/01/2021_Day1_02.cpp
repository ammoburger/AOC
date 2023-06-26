#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

bool compareDepth(int nDepth, int pDepth)
{
    if (nDepth > pDepth)
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
    vector<int> depthVec;

    while (getline(inputFile, line))
    {
        depth = stoi(line);        // convert string to integer
        depthVec.push_back(depth); // push integer into vector
    }

    for (int i = 0; i < depthVec.size() + 3; i++)
    {
        int oldDepth = depthVec[i] + depthVec[i + 1] + depthVec[i + 2];
        int newDepth = depthVec[i + 1] + depthVec[i + 2] + depthVec[i + 3];

        if (compareDepth(newDepth, oldDepth))
        {
            finalScore++;
        }
    }
    cout << finalScore; // print score
}
