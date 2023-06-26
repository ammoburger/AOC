#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>

using namespace std;

template <typename T>
void printSet(T &numberset)
{
    for (auto &nums : numberset)
    {
        cout << nums << " ";
    }
}
int charInt(char x) // convert read char to visible int val
{
    int i = int(x - '0');
    return i;
}
bool isNumber(char c)
{
    if (isdigit(c))
    {
        return true;
    }
    return false;
}
int main()
{
    string newLine;
    ifstream inputFile;
    inputFile.open("04input.txt");

    set<int> numSet1;
    set<int> numSet2;

    int nBegin1 = 0;
    int nBegin2 = 0;
    int nEnd1 = 0;
    int nEnd2 = 0;

    int digitCount = 0;

    while (!inputFile.eof())
    {
        getline(inputFile, newLine);
        // 3-4,5,9
        // split on ,
        // ["2-41", "5-9"]
        // split on -
        // [["2", "41"], ["5", "9"]]
        // or
        // split on - and conver to int when pushing
        // [[2, 41], [5, 9]]

        for (int i = 0; i < newLine.size(); i++) // get number of digits in line
        {
            if (isNumber(newLine[i]))
            {
                digitCount++;
                cout << digitCount;
            }
        }

        // if (digitCount == 4)
        // {
        //     int nBegin1 = charInt(newLine.at(0));
        //     // cout << "   " << nBegin1 << "   ";
        //     int nEnd1 = charInt(newLine.at(2));
        //     // cout << "   " << nEnd1 << "   ";
        //     int nBegin2 = charInt(newLine.at(4));
        //     // cout << "   " << nBegin2 << "   ";
        //     int nEnd2 = charInt(newLine.at(6));
        //     // cout << "   " << nEnd2 << "   ";

        //     cout << " FOUR DIGITS ";
        // }
        // if (digitCount == 5)
        // {
        //     // stringstream
        //     //  cout << "VALUE: (" << newLine.at(0) << ")";
        //     if (newLine.at(0) == 1)
        //     {
        //         int nBegin1 = charInt(newLine.at(0));
        //         cout << "   " << nBegin1 << "   ";
        //         int nEnd1 = charInt(newLine.at(2)) * 10 + charInt(newLine.at(3));
        //         cout << "   " << nEnd1 << "   ";
        //         cout << "VAR 1";
        //     }
        //     else if (newLine.at(0) != 1)
        //     {
        //         int nBegin1 = charInt(newLine.at(0));
        //         cout << "   " << nBegin1 << "   ";
        //         int nEnd1 = charInt(newLine.at(2));
        //         cout << "   " << nEnd1 << "   ";
        //         cout << "VAR 2";
        //     }

        //     cout << " FIVE DIGITS ";
        // }

        ////////////?    INSERT RESULTS   ///////////////
        for (int i = nBegin1; i <= nEnd1; i++)
        {
            numSet1.insert(i);
        }

        for (int i = nBegin2; i <= nEnd2; i++)
        {
            numSet2.insert(i);
        }

        // printSet(numSet1);
        // cout << " | ";
        // printSet(numSet2);

        if (includes(numSet1.begin(), numSet1.end(), numSet2.begin(), numSet2.end()))
        {
            cout << " = TRUE" << endl;
        }
        else
        {
            cout << " = FALSE" << endl;
        }

        //? RESET STUFF FOR NEXT LINE //
        numSet1.clear();
        numSet2.clear();
        digitCount = 0;
    }
}