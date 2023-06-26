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

    vector<set<int>> leftVSets;
    vector<set<int>> rightVSets;

    set<int> numSet1;
    set<int> numSet2;

    while (getline(inFile, newString))
    {

        tokenize(newString, delim, sOut); // split based on commas, sOut = blank string
        numSet1.insert(lineCount);
    }
    for (auto &newString : sOut)
    {
        lineCount++;
        string strMod = "", deli = "-", lString, rString; // init delimiter..and friends
        int leftNum = 0;
        int rightNum = 0;

        words.push_back(newString); // split based on even & odd vec entries
        if (words.size() % 2 == 0)
        { //* RIGHT SIDE*//

            strMod = newString, lString = strMod.substr(0, strMod.find_first_of(deli));
            rString = strMod.substr(strMod.find(deli) + 1);
            leftNum = stoi(lString), rightNum = stoi(rString);
            lnumVec.push_back(leftNum);
            rnumVec.push_back(rightNum);
            cout << leftNum << " ";
            cout << rightNum << " " << endl;
        }
        else
        { //* LEFT SIDE*//

            strMod = newString, lString = strMod.substr(0, strMod.find_first_of(deli));
            rString = strMod.substr(strMod.find(deli) + 1);
            leftNum = stoi(lString), rightNum = stoi(rString);
            lnumVec.push_back(leftNum);
            rnumVec.push_back(rightNum);
            cout << leftNum << " ";
            cout << rightNum << " ";
        }
    }
}
