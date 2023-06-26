#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream> // for file stream

using namespace std;

template <typename T>
void print(T &vecOfElements, std::string delimeter = " , ")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}

char findOverlap(string left, string right)
{
    for (auto &ltr : left)
    {
        for (auto &rtr : right)
        {
            if (rtr == ltr)
            {
                return ltr;
            }
        }
    }
    return '-';
}

int main()
{
    string line;
    int pscore = 0;
    ifstream myinput("03_TEST_INPUT.txt"); // Input file stream

    map<char, int> priority; // Initialize container

    const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 52; ++i)
    {
        priority[letters[i]] = i + 1; // Assign priority to letters
    }

    if (myinput.is_open()) // input file open
    {
        while (getline(myinput, line))
        {
            int halfnum = line.size() / 2; // get half the size of the line

            //* SPLIT STRINGS *//
            string lhalf = line.substr(0, halfnum);

            string rhalf = line.substr(halfnum);

            char overlap = findOverlap(lhalf, rhalf);

            pscore += priority[overlap];
        }
    }
    cout << pscore;
}

// String
// Split into two halves ONE  |  TWO
// new function called findOverlap(one, two) -> returns THE OVERLAPPED THING
// loop through one, check each element of two to see if its === the thing in one.
// for (auto &x : one) {
//     for (auto &y : two) {
//         if ( x == y) return x;
//     }
// }
// char thing = findOverlap(one, two);
// priority[thing];
// split
// find overlap
// score_item