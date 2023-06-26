#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int numb_argument, char *arg_strings[])
{
    map<string, int> rcodemap{
        {"A X", 3},
        {"A Y", 4},
        {"A Z", 8},
        {"B X", 1},
        {"B Y", 5},
        {"B Z", 9},
        {"C X", 2},
        {"C Y", 6},
        {"C Z", 7}};

    int totalscore;
    int score;

    while (!cin.eof())
    {
        string match_result;
        int score;
        getline(cin, match_result);

        if (cin.fail())
        {
            break;
        }

        if (match_result.size() > 0)
        {
            score = rcodemap[match_result];
            totalscore = totalscore + score;
        }
    }
    cout << totalscore;
}