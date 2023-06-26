#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetRoundInfo(string atks)
{
    int roundscore;
    string attackoutput;
    //
    string pattack;  // playerattack
    string enattack; // enemeyattack

    if (atks.size() >= 3)
    {
        pattack = atks.at(0);  // first letter
        enattack = atks.at(2); // second letter   (2 because 1 is a space)
    }

    attackoutput.append(pattack);
    attackoutput.append(enattack);
    return attackoutput;
}

int GetRoundResults(string codes)
{ //  4pt    8pt  3pt   1pt    5pt   9pt   7pt   2pt   6pt
    vector<string> atkcodelookup = {"AX", "AY", "AZ", "BX", "BY", "BZ", "CX", "CY", "CZ"};

    int score_return;
    string attack_code = codes;

    string winc = "Z";
    string drawc = "Y";
    string losec = "X";

    if (attack_code.find(winc) != string::npos)
    {
        
        cout << "WIN";
    }

    return score_return;
}

int main(int argc, char *argv[])
{
    int roundnum = 0;
    int score = 0;
    int final_score = 0;
    // Match Conditions
    vector<int> match_outcomes;

    while (!cin.eof())
    {
        string newline;
        getline(cin, newline);

        if (cin.fail())
        {
            break;
        }

        if (newline.size() > 0)
        {
            string atkcd;
            atkcd = GetRoundInfo(newline);
            score = GetRoundResults(atkcd);

            final_score = final_score + score;
        }
    }
    cout << final_score;
}
