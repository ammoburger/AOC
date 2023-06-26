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

    int lineCount = 0;

    vector<int> lnumVec;
    vector<int> rnumVec;

    vector<set<int>> unoVecSet;

    set<int> numSet1;
    set<int> numSet2;

    while (getline(inFile, newString))
    {
        istringstream isstream(newString);
        int sum = 0, next = 0;
        while (isstream >> next)
            sum += next;
        cout << next;

        string deli = " ";
        string f1 = newString.substr(0, newString.find(' '));
        int a1 = stoi(f1);
        rnumVec.push_back(a1);
        string f2 = newString.substr(newString.find(' '));
        int a2 = stoi(f2);
        lnumVec.push_back(a2);

        for (int z = 0; z < lnumVec.size(); z++)
        {
            vector<int> a;
            for (int i = rnumVec[z]; i <= lnumVec[z]; i++)
            {
                a.push_back(i);
                // cout << i << " ";
            }

            for (auto x : a)
            {
                // cout << x << " ";
            }
        }
    }

    // cout << rnumVec.size();
}
