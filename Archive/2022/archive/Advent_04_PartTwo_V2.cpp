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
template <class I1, class I2>
bool have_common_element(I1 first1, I1 last1, I2 first2, I2 last2)
{
    while (first1 != last1 && first2 != last2)
    {
        if (*first1 < *first2)
            ++first1;
        else if (*first2 < *first1)
            ++first2;
        else
            return true;
    }
    return false;
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

    for (int i = 0; i < vSetsOne.size(); i++)
    {
        set<int> s1 = vSetsOne.at(i), s2 = vSetsTwo.at(i); // define the 2 sets to compare

        if (have_common_element(s1.begin(), s1.end(), s2.begin(), s2.end()))
        {
            finalScore++;
        } // anus 8=D~
    }
    cout << finalScore; // print final score
}
