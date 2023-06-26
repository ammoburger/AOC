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

    while (!inputFile.eof())
    {
        getline(inputFile, newLine);

        // //////////////////?     THE FULL MONTY     //////////////////////////
        if ((newLine.size() == 10))
        {
            if ((newLine.at(1)) || newLine.at(1) && newLine.at(4) != ',' && newLine.at(6) != '-' && newLine.at(8) == '-')
            {
                nBegin1 = charInt(newLine.at(0)) * 10 + charInt(newLine.at(1)); // append int (e.g. 3 5 = 3*10+5)

                nEnd1 = charInt(newLine.at(3)) * 10 + charInt(newLine.at(4));

                nBegin2 = charInt(newLine.at(6)) * 10 + charInt(newLine.at(7));

                nEnd2 = charInt(newLine.at(9)) * 10 + charInt(newLine.at(10));
            }
        }

        else if (newLine.size() == 10)
        {

            if ((newLine.at(1)) == '-')
            {
                nBegin1 = charInt(newLine.at(0));
                nEnd1 = charInt(newLine.at(2)) * 10 + charInt(newLine.at(3));
                // cout << nEnd1;

                nBegin2 = charInt(newLine.at(5)) * 10 + charInt(newLine.at(6));
                nEnd2 = charInt(newLine.at(9));
                // cout << nBegin2;
            }
            else
            {
                nBegin1 = charInt(newLine.at(0));
                // cout << nBegin1 << endl;
                nEnd1 = charInt(newLine.at(0)) * 10 + charInt(newLine.at(1));
                // cout << nEnd1;

                nBegin2 = charInt(newLine.at(5));
                nEnd2 = charInt(newLine.at(9)) * 10 + charInt(newLine.at(6));
            }
        }

        ////////////?    INSERT RESULTS   ///////////////
        for (int i = nBegin1; i <= nEnd1; i++)
        {
            numSet1.insert(i);
            // cout << i << endl;
        }

        for (int i = nBegin2; i <= nEnd2; i++)
        {
            numSet2.insert(i);
            // cout << i << endl;
        }

        printSet(numSet1);
        cout << " | ";
        printSet(numSet2);

        if (includes(numSet1.begin(), numSet1.end(), numSet2.begin(), numSet2.end()))
        {
            cout << " = TRUE" << endl;
        }
        else
        {
            cout << " = FALSE" << endl;
        }

        //? ERASE SETS FOR NEXT LINE //
        numSet1.clear();
        numSet2.clear();
    }
}