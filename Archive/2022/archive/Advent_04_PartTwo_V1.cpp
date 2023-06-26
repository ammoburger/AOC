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
void printSet(T &numberset)
{
    for (auto &nums : numberset)
    {
        cout << nums << "__";
    }
}
template <typename T>
void print(T &vecOfElements, string delimeter = "|||||")
{
    for (auto elem : vecOfElements)
        cout << elem << delimeter;
    cout << endl;
}
void tokenize(string const &str, const char delim, vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) // stringstream, string, delim
    {
        out.push_back(s);
    }
}

int main()
{
    string newString;
    ifstream inFile;
    inFile.open("04input.txt");

    vector<string> words;
    vector<string> sOut;
    int lineCount = 0;

    vector<int> lnumVec;
    vector<int> rnumVec;

    const char delim = ',';

    vector<set<int>> vSetsOne;
    vector<set<int>> vSetsTwo;

    set<int> numSet1;
    set<int> numSet2;

    while (getline(inFile, newString))
    {
        lineCount++;
        tokenize(newString, delim, sOut); // split based on commas, sOut = blank string
    }
    for (auto &newString : sOut)
    {
        string strMod = "", deli = "-", lString, rString; // init delimiter..and friends
        int leftNum = 0;
        int rightNum = 0;

        set<int> setOne; // set
        set<int> setTwo;

        words.push_back(newString); // split based on even & odd vec entries
        if (words.size() % 2 == 1)
        {

            strMod = newString, lString = strMod.substr(0, strMod.find_first_of(deli));
            rString = strMod.substr(strMod.find(deli) + 1);
            leftNum = stoi(lString), rightNum = stoi(rString);

            for (int i = leftNum; i <= rightNum; i++)
            {
                setOne.insert(i); // Number Set ONE
                cout << i << " ";
            }
            // cout << endl;
            vSetsOne.push_back(setOne);

            // cout << endl
            //      << leftNum << " ";  //* Column 1 *//
            // cout << rightNum << " "; //* Column 2 *//
        }
        else
        {
            strMod = newString, lString = strMod.substr(0, strMod.find_first_of(deli));
            rString = strMod.substr(strMod.find(deli) + 1);
            leftNum = stoi(lString), rightNum = stoi(rString);

            for (int i = leftNum; i <= rightNum; i++)
            {
                setTwo.insert(i); // Number Set TWO
                cout << i << " ";
            }
            // cout << endl;
            vSetsTwo.push_back(setTwo);

            // cout << leftNum << " ";          //* Column 3 *//
            // cout << rightNum << " " << endl; //* Column 4 *//
        }
        cout << endl;
    }
    // Display the vector of sets
    // for (int i = 0; i < vSetsOne.size(); i++)
    // {

    //     for (auto x : vSetsOne[i]) //  ONE
    //         cout << x << " ";
    //     cout << endl;
    // }
    // for (int i = 0; i < vSetsTwo.size(); i++)
    // {

    //     for (auto x : vSetsTwo[i]) // TWO
    //         cout << x << " ";
    //     cout << endl;
    // }
    int finalScore = 0;
    int score = 0;
    for (int i = 0; i < vSetsOne.size(); i++)
    {

        set<int> s1 = vSetsOne.at(i);
        set<int> s2 = vSetsTwo.at(i);

        // inter = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), s1.begin());
    }

    // cout << finalScore;
}
