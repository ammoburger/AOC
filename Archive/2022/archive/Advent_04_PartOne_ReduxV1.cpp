#include <iostream>
#include <string>
#include <set>
#include <vector>
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
void tokenize(string const &str, const char del, vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);

    string s;
    while (getline(ss, s, del)) // stringstream, string, delim
    {
        out.push_back(s);
    }
}

int main()
{
    string newString;
    vector<string> words, sOut;
    ifstream inFile;
    inFile.open("04input.txt");

    const char delComma = ',', delDash = '-'; //* const char delimiters
    vector<set<int>> vSetsOne;                // initialize vector of int sets
    vector<set<int>> vSetsTwo;

    int finalScore = 0; // initialize finalScore counter

    while (getline(inFile, newString)) //! Read every line from input file
    {
        tokenize(newString, delComma, sOut); // split based on commas, sOut = output
    }
    for (auto &newString : sOut) //! remove commas,dashes  convert strings to int and put in two sets
    {
        string strMod = "", lString, rString; // init delimiter and friends
        int leftNum = 0, rightNum = 0;
        set<int> setOne, setTwo;

        words.push_back(newString); // split based on even & odd vec entries
        if (words.size() % 2 == 1)
        {
            strMod = newString, lString = strMod.substr(0, strMod.find_first_of(delDash));
            rString = strMod.substr(strMod.find(delDash) + 1);
            leftNum = stoi(lString), rightNum = stoi(rString); //? Columns 1-2

            for (int i = leftNum; i <= rightNum; i++)
            {
                setOne.insert(i); // Number Set ONE
            }
            vSetsOne.push_back(setOne); // add to vector of sets
        }
        else
        {
            strMod = newString, lString = strMod.substr(0, strMod.find_first_of(delDash));
            rString = strMod.substr(strMod.find(delDash) + 1);
            leftNum = stoi(lString), rightNum = stoi(rString); //?  Columns 2-4

            for (int i = leftNum; i <= rightNum; i++)
            {
                setTwo.insert(i); // Number Set TWO
            }
            vSetsTwo.push_back(setTwo); // add to vector of sets
        }
    }

    for (int i = 0; i < vSetsOne.size(); i++) //! check if sets contain the other and set final score
    {
        set<int> s1 = vSetsOne.at(i), s2 = vSetsTwo.at(i); // define the 2 sets to compare
        if (includes(s1.begin(), s1.end(), s2.begin(), s2.end()) || includes(s2.begin(), s2.end(), s1.begin(), s1.end()))
        {
            finalScore++; // increment score if the sets contain the other //?(e.g. (123_&_123) = true, (12_&_34) = false
        }
    }
    cout << finalScore; // print final score
}
