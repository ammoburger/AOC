#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int getDelta(string instruction, int force)
{
    if (instruction == "up")
    {
        return -force;
    }
    return force;
}

int main()
{
    string line;
    ifstream inputFile;
    inputFile.open("2021_02_input.txt");

    int horiz = 0, depth = 0, aim = 0;

    while (getline(inputFile, line))
    {
        string direction = line.substr(0, line.find(' '));
        int delta = getDelta(direction, stoi(line.substr(line.find(' '))));

        if (direction == "forward")
        {
            horiz += delta;
            depth += aim * delta;
        }
        if (direction == "down")
        {
            aim += delta;
        }
        if (direction == "up")
        {
            aim += delta;
        }
    }
    cout << horiz * depth;
}