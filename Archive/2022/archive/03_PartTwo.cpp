#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream> // for file stream

using namespace std;

template <typename T>
void print(T &vecOfElements, std::string delimeter = " , ")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}

char findOverlap(string left, string right)
{
    for (auto &ltr : left)
    {
        for (auto &rtr : right)
        {
            if (rtr == ltr)
            {
                return ltr;
            }
        }
    }
    return '-';
}

char findBadge(string line1, string line2, string line3)
{
    for (auto &let1 : line1) // auto = whatever the type is, we'll use that
    {
        for (auto &let2 : line2)
        {
            for (auto &let3 : line3)
            {
                //!  N_O_T     if(let1 == let3)
                if (let1 == let2 && let2 == let3 && let3 == let1) //?  (1 == 2 == 3)
                    if (let1 == let3)
                    {
                        return let3;
                    }
            }
        }
    }
    cout << "broke";
    return '-';
}

int main()
{
    string line;
    int linecount = 0;
    int pFinalScore = 0;
    vector<string> lineGroup;
    // cumload.txt (final output)   testcum (test input)
    ifstream myinput("cumload.txt"); // Input file stream

    map<char, int> priority; // Initialize container
    const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 52; ++i)
    {
        priority[letters[i]] = i + 1; // Assign priority to letters
    }

    if (myinput.is_open()) // input file open
    {
        while (getline(myinput, line))
        {
            linecount++; // get and increment line count

            if (lineGroup.size() < 3 && line.size() > 0)
            {
                lineGroup.push_back(line);
            }
            else if (lineGroup.size() == 3)
            {
                char badge = findBadge(lineGroup.at(0), lineGroup.at(1), lineGroup.at(2));
                // cout << badge;
                // pFinalScore += priority[badge];
                // print(lineGroup);
                lineGroup.clear();
            }

            // store reference to individual lines in group of three
            // call findBadge(line1, line2, line3)
            // get priority
            // find sum of priorities of groups of three
        }
    }

    // pFinalScore = priority['Z'];
    // cout << pFinalScore << endl
    //      << endl;
}
