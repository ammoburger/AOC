#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

template <typename D>
void print(D &vecOfElements, std::string delimeter = "_")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}
template <typename T>
void printSet(T &numberset)
{
    for (auto &nums : numberset)
    {
        cout << nums << " ";
    }
}

int main()
{
    string newString;
    ifstream inputFile;
    inputFile.open("04input.txt");

    set<int> numSet1{1, 2, 3}; // e.g. {1, 2, 3, 4};
    set<int> numSet2{2, 3};    //     {2, 3};

    vector<string> words;
    vector<int> numbers;

    while (!inputFile.eof())
    {
        while (getline(inputFile, newString, ','))

            words.push_back(newString);
        // print(words);

        //*==========================================================*//

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

        ////? RESET STUFF FOR NEXT LINE ////
        numSet1.clear();
        numSet2.clear();
    }
}