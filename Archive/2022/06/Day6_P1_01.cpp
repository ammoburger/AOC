#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;
template <typename T>
void printSet(T &numberset)
{
    for (auto &nums : numberset)
    {
        cout << nums << " " << endl;
    }
}

bool isUnique(string str)
{
    // 1 2 3 4
    // 2 3 4
    // 3 4
    // 4
    for (int j = 0; j < str.length(); j++)
    {
        for (int k = j + 1; k < str.length(); k++)
        {
            if (str.at(j) == str.at(k))
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
    string nstr;

    while (getline(inputFile, nstr))
    {
        // 4 characters.
        // 1 2 3 4 5 6 7 8 9
        // NOT
        // [1 2 3 4]
        //          [5 6 7 8]
        // But instead:
        // [1 2 3 4]
        //   [2 3 4 5]
        //     [3 4 5 6]
        // If you're checking i through i+3, when do you need to stop your for loop?
        // How do you check 4 elements at a time, given i?
        // You don't need any other arrays, or to store anything else, you can return the index if you find a unique 4 string.
        // [ 1, 2, 3 ] j
        //     k

        // cout << nstr << endl;
        int markerSize = 14;

        for (int i = 0; i <= nstr.size() - markerSize; i++)
        {
            if (isUnique(nstr.substr(i, markerSize)))
            {
                cout << i + markerSize << endl;
                return 0;
            }
        }
    }
}