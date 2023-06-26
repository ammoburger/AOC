#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // for 'find' & 'sort' function
#include <numeric>   // for 'accumulate' function
#include <fstream>   // for file stream

using namespace std;

//* PRINT VECTOR ELEMENTS *//
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
}

int main()
{
    string line;
    int linenum; // Line counter

    ifstream myinput("03_TEST_INPUT.txt"); // Input file stream

    map<char, int> priority; // Initialize container
    map<char, int> cMap;     // store frequency of priorities that appear on both sides

    vector<int> lPrios;    // unique priorities on each half of a line (left & right)
    vector<int> rPrios;    //
    vector<int> combPrios; // combined unique priorities of each half
    vector<int> sumPrios;  // sum of priorities that match both sides

    const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 52; ++i)
    {
        priority[letters[i]] = i + 1; // Assign priority to letters
    }

    if (myinput.is_open()) // input file open
    {
        while (getline(myinput, line))
        {
            linenum++; // increment lines read from file
            int linescore = 0;
            int halfnum = line.size() / 2; // get half the size of the line

            /*////////////////////////////////////*/
            //* SPLIT STRINGS *//
            // LEFT

            string lhalf;
            lhalf = line.substr(0, halfnum);
            for (int a = 0; a < lhalf.size(); a++)
            {
                int lp = priority[line.at(a)]; // check priority at(a)

                if (find(lPrios.begin(), lPrios.end(), lp) == lPrios.end()) // add key(lp) in vec if not there
                {
                    lPrios.push_back(lp);
                }
            }

            // RIGHT
            string rhalf;

            rhalf = line.substr(halfnum, halfnum);

            for (int z = 0; z < rhalf.size(); z++)
            {
                int rp = priority[rhalf.at(z)];
                if (find(rPrios.begin(), rPrios.end(), rp) == rPrios.end())
                {
                    rPrios.push_back(rp);
                }
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

            /*////////////////////////////////////*/
            //*  W E L C O M E   T O    H E L L  *//
            for (int i = 0; i < lPrios.size(); i++) // put unique priorities into new vec per half
            {
                combPrios.push_back(lPrios.at(i));
            }
            for (int i = 0; i < rPrios.size(); i++)
            {
                combPrios.push_back(rPrios.at(i));
            }

            for (auto &elem : combPrios)
            {
                auto result = cMap.insert(pair<char, int>(elem, 1)); // put duplicate/unqie/combined priorities in new vec
                if (result.second == false)
                    result.first->second++;
            }

            for (auto &elem : cMap)
            {
                if (elem.second > 1)
                {
                    linescore = elem.first;
                    sumPrios.push_back(linescore); // check against a new map :-(
                }
            }

            //* CLEAR VECTORS/MAPS *//
            cMap.clear();
            combPrios.clear();
            lPrios.clear(); // clear vectors so next line isn't polluted
            rPrios.clear(); //
        }
    }
    cout << accumulate(sumPrios.begin(), sumPrios.end(), 0) << endl; // print sum
}