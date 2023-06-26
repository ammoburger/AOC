#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
int applyForce(string instruction, int amount)
{

    int num = 0;
    if (instruction.find("forward") != string::npos)
    {
        num = amount;
        return num;
    }
    else
    {
        return num = 0;
    }
    if (instruction.find("down") != string::npos)
    {
        num = amount;
        return num;
    }
    else
    {
        return num = 0;
    }
    if (instruction.find("up") != string::npos)
    {
        num = amount;
        return num;
    }
    else
    {
        num = 0;
        return num;
    }
}
int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_02_input.txt");

    int horiz = 0, depth = 0;

    int test = 0;
    while (getline(inputFile, line))
    {
        string instruction = line.substr(0, line.find(' '));
        int delta = stoi(line.substr(line.find(' ')));

        horiz += applyForce(instruction, delta);
        depth += applyForce(instruction, delta);
    }
    // cout << depth << endl;
    cout << depth << endl;
}
// forward  = horiz + delta
// down x   = depth + delta
// up   x   = depth - delta