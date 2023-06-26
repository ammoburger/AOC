#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

template <typename T>
void print(T &vecOfElements, std::string delimeter = " |X| ")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}

int main()
{
    string newString;
    ifstream inFile;
    inFile.open("04input.txt");

    vector<string> words;
    vector<string> leftWords;
    vector<string> rightWords;

    vector<int> leftNums;
    vector<int> rightNums;

    vector<int> Beg1;
    vector<int> End1;
    vector<int> Beg2;
    vector<int> End2;

    set<int> numSet1;
    set<int> numSet2;

    while (getline(inFile, newString, '\n'))
    {
        words.push_back(newString); // split string on new lines
    }

    string lStrings = "";
    for (int i = 0; i < words.size(); i++)
    {
        string modToken = "";
        string mstr = words[i];
        string del = ",";
        modToken = mstr.substr(0, mstr.find(del));
        leftWords.push_back(modToken);
        lStrings.append(modToken);
        lStrings.append("-"); // append a dash to fix bad number stitching
    }
    // print(leftWords);

    stringstream leftStream(lStrings);

    while (getline(leftStream, lStrings, '-'))
        leftNums.push_back(stoi(lStrings));

    // print(leftNums);
    for (int i = 0; i <= leftNums.size(); i++)
    {
        int nEnd1 = 0;
        int nBegin1 = 0;
        if (i % 2 != 0 && i != 0)
        {
            nEnd1 = leftNums[i];
            End1.push_back(nEnd1);
            // cout << nEnd1 << endl;
        }
        else
        {
            nBegin1 = leftNums[i];
            Beg1.push_back(nBegin1);
            // cout << leftNums[i] << endl;
        }
        // print(Beg1);
    }

    cout << End1.size();
    // vector<int>::iterator iter1;
    // for (iter1 = Beg1.begin(); iter1 != End1.end(); iter1++)
    //     cout << *iter1 << " ";
}
