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
        pattack = atks.at(0);  //first letter
        enattack = atks.at(2); //second letter   (2 because 1 is a space)
    }

    attackoutput.append(pattack);
    attackoutput.append(enattack);
    return attackoutput;
}

int GetRoundResults(string codes)
{                               //  4pt    8pt  3pt   1pt    5pt   9pt   7pt   2pt   6pt      
    vector<string> atkcodelookup = {"AX", "AY", "AZ", "BX", "BY", "BZ", "CX", "CY", "CZ"};

    int score_return;
    string attack_code = codes;

    for (int i = 0; i < atkcodelookup.size(); i++)
    {

        if (attack_code == atkcodelookup[i])
        {

            if (attack_code == atkcodelookup[0]) // 0 == AX
            {
                // assign score
                score_return = 4;
            }
            else if (attack_code == atkcodelookup[1])
            {
                // cout << "ONE";
                score_return = 8;
            }
            else if (attack_code == atkcodelookup[2])
            {
                // cout << "TWO";
                score_return = 3;
            }
            else if (attack_code == atkcodelookup[3])
            {
                // cout << "THREE";
                score_return = 1;
            }
            else if (attack_code == atkcodelookup[4])
            {
                // cout << "FOUR";
                score_return = 5;
            }
            else if (attack_code == atkcodelookup[5])
            {
                // cout << "FIVE";
                score_return = 9;
            }
            else if (attack_code == atkcodelookup[6])
            {
                // cout << "SIX";
                score_return = 7;
            }
            else if (attack_code == atkcodelookup[7])
            {
                // cout << "SEVEN";
                score_return = 2;
            }
            else if (attack_code == atkcodelookup[8])
            {
                // cout << "EIGHT";
                score_return = 6;
            }   
        }
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
