#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool CheckLetter(string line, string letter)
{
    if (line.find(letter) == string::npos)
    {
        return true;
    }
    return false;
}

string GetMatchDetails(string coden)
{
    if (coden.find("X") != string::npos) // Lose check against whole string
    {

        return "lose";
    }

    else if (coden.find("Y") != string::npos) // Draw
    {
        return "draw";
    }

    else if (coden.find("Z") != string::npos) // Win
    {
        return "win";
    }

    return "No Valid Returns!";
}

int GetMatchScore(string code, string details)
{
    int matchscore = 0;
    string match_outcome = details;

    //=============================================//
    //                  L O S E                     //
    //=============================================//

    if (match_outcome == "lose")
    {
        if (!code.find("A")) // A = Enemy uses 'Rock'
        {
            matchscore = 3; // To LOSE against 'Rock'...I use Scissors (which is 3pts)
        }
        else if (!code.find("B"))
        {
            matchscore = 1;
        }
        else if (!code.find("C"))
        {
            matchscore = 2;
        }
        return matchscore;
    }

    //=============================================//
    //                 D R A W                     //
    //=============================================//

    if (match_outcome == "draw")
    {
        if (!code.find("A")) // A = Enemy uses 'Rock'
        {
            matchscore = 4;
        }
        else if (!code.find("B"))
        {
            matchscore = 5;
        }
        else if (!code.find("C"))
        {
            matchscore = 6;
        }
        return matchscore;
    }
    //=============================================//
    //                   W I N                     //
    //=============================================//

    if (match_outcome == "win")
    {
        if (!code.find("A")) // A = Enemy uses 'Rock'
        {
            matchscore = 8;
        }
        else if (!code.find("B"))
        {
            matchscore = 9;
        }
        else if (!code.find("C"))
        {
            matchscore = 7;
        }
        return matchscore;
    }

    return 420;
}

int main(int numb_argument, char *arg_strings[])
{
    map<int, string> rcodemap{{1, "A X"},   
    {2, "A Y"}, 
    {3, "A Z"}, 
    {4, "B X"},                  //                                   / /
    {5, "B Y"},                 //       M A T C H    C O D E S      / /
    {6, "B Z"},                //                                   / /
    {7, "C X"}, 
    {8, "C Y"},              //               8==D ~ ~
    {9, "C Z"}};

    map<int, string>::iterator it;   // declare map iterator
    int totalscore;                 

    while (!cin.eof())      // while 'end of file' is false (AKA script is running)
    {
        string newline;
        getline(cin, newline);  //reads a line of input
        if (cin.fail())
        {
            break;
        }

        if (newline.size() > 0)
        {
            string mcode; // match code
            string mdets; // match details
            int score; 

            for (it = rcodemap.begin(); it != rcodemap.end(); it++)         // iterate through match codes
            {
                mcode = it->second;                                         // mcode is map element (e.g. "A X")

                if (mcode == newline)  //  -     -     -     -     -        // check value against line of input
                {
                    mdets = GetMatchDetails(mcode);                         // send match code to function return (Win/Lose/Draw)
                    score = GetMatchScore(mcode, mdets);                    // send code and match outcome and return match score
                }
            }
            totalscore = totalscore + score;                                // add match score to total score
        }
    }
    cout << totalscore;                                                     // output the total score when script ends
}