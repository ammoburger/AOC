#include "C:\Users\Spencer\projects\AOC\FunctionLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void printColorText(string txt, int color, bool newLine = false)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int defaultColor = 7;
    ss_setTextColor(hConsole, color);
    cout << txt;
    if (newLine)
    {
        cout << endl;
    }

    ss_setTextColor(hConsole, defaultColor);
};

namespace playerMoves
{
    enum turn
    {
        Rock = 0,
        Paper,
        Scissors
    };

    enum result
    {
        Win = 0,
        Loss,
        Draw
    };
}

using namespace playerMoves;

class Round
{

public:
    Round(int roundID, turn themMove, turn usMove)
    {
        this->roundID = roundID;
        this->theirMove = themMove;
        this->myMove = usMove;
    };

    int getRoundID()
    {
        return this->roundID;
    };

    int firstStrategyGuide()
    {
        int scoredOutcome = 0, scoredMove = 0;
        turn myTurn = myMove;

        switch (myTurn)
        {
        case Rock:
        {
            scoredMove = 1;
            break;
        }
        case Paper:
        {
            scoredMove = 2;
            break;
        }
        case Scissors:
        {
            scoredMove = 3;
            break;
        }
        default:
        {
            cout << "ERROR";
        }
        };

        scoredOutcome = roundOutcome(theirMove, myMove);

        int finalScore = scoredMove + scoredOutcome;

        return finalScore;
    };

    int secondStrategyGuide()
    {
        int scoredOutcome = 0, scoredMove = 0;
        turn myTurn = myMove;
        result riggedResult;
        bool isRigged = true;

        switch (myTurn)
        {
        case Rock:
        {
            riggedResult = Loss;
            break;
        }
        case Paper:
        {
            riggedResult = Draw;
            break;
        }
        case Scissors:
        {
            riggedResult = Win;
            break;
        }
        default:
        {
            cout << "ERROR";
        }
        };

        scoredOutcome = roundOutcome(theirMove, myMove, isRigged, riggedResult);

        int finalScore = scoredOutcome;

        return finalScore;
    };

private:
    int roundID;
    turn theirMove;
    turn myMove;

    map<pair<turn, turn>, int> scores;
    map<pair<result, turn>, turn> rigCodes;

    int roundOutcome(turn them, turn us, bool rigged = false, result rigResult = Draw)
    {
        int rScore = 0;
        int moveScore = 0;
        turn updatedMyMove = us;

        //    [ them ] [ me ]
        scores[{Rock, Paper}] = 6;
        scores[{Rock, Scissors}] = 0;
        scores[{Paper, Rock}] = 0;
        scores[{Paper, Scissors}] = 6;
        scores[{Scissors, Rock}] = 6;
        scores[{Scissors, Paper}] = 0;
        scores[{Rock, Rock}] = 3;
        scores[{Paper, Paper}] = 3;
        scores[{Scissors, Scissors}] = 3;

        if (rigged)
        {

            rigCodes[{Win, Rock}] = Paper;
            rigCodes[{Win, Paper}] = Scissors;
            rigCodes[{Win, Scissors}] = Rock;

            rigCodes[{Loss, Rock}] = Scissors;
            rigCodes[{Loss, Paper}] = Rock;
            rigCodes[{Loss, Scissors}] = Paper;

            rigCodes[{Draw, Rock}] = Rock;
            rigCodes[{Draw, Paper}] = Paper;
            rigCodes[{Draw, Scissors}] = Scissors;

            if (rigResult == Win)
            {
                updatedMyMove = rigCodes[{Win, them}];
            }

            else if (rigResult == Loss)
            {
                updatedMyMove = rigCodes[{Loss, them}];
            }

            else if (rigResult == Draw)
            {
                updatedMyMove = rigCodes[{Draw, them}];
            }

            if (updatedMyMove == Rock)
            {
                moveScore = 1;
            }

            else if (updatedMyMove == Paper)
            {
                moveScore = 2;
            }

            else if (updatedMyMove == Scissors)
            {
                moveScore = 3;
            }

            int riggedScore = scores[{them, updatedMyMove}];
            return riggedScore + moveScore;
        }

        if (us == them)
        {
            rScore = 3;
            return rScore;
        }

        return rScore = scores[{them, us}];
    }
};

void useStrategyGuides()
{

    fstream myInput;
    myInput.open("2022_02_input.txt");
    string line;

    vector<Round *> rounds;

    int roundNum = 0, firstTotalScore = 0, secondTotalScore = 0;
    turn usMove;
    turn themMove;

    map<char, turn> moves;

    moves['A'] = Rock, moves['X'] = Rock;
    moves['B'] = Paper, moves['Y'] = Paper;
    moves['C'] = Scissors, moves['Z'] = Scissors;

    while (getline(myInput, line))
    {
        roundNum += 1;

        char them = line.at(0), us = line.at(2);

        themMove = moves[them], usMove = moves[us];

        rounds.push_back(new Round(roundNum, themMove, usMove));
    }

    for (int i = 0; i < rounds.size(); i++)
    {
        firstTotalScore += rounds.at(i)->firstStrategyGuide();
        secondTotalScore += rounds.at(i)->secondStrategyGuide();
    }
    string messageOne = "Part One: ";
    string messageTwo = "Part Two: ";
    messageOne.append(to_string(firstTotalScore));
    messageTwo.append(to_string(secondTotalScore));

    printColorText(messageOne, 2, true);
    printColorText(messageTwo, 5);
};

int main()
{
    useStrategyGuides();

    return 0;
};