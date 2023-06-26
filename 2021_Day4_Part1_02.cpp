#include "FunctionLibrary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <windows.h>

using namespace std;

template <typename T>
void print(T &vecOfElements, string delimeter = ",")
{
    for (auto elem : vecOfElements)
        cout << elem << delimeter << endl;
};

void printColorText(string txt, int color, bool firstLine = false)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int defaultColor = 7;
    ss_setTextColor(hConsole, color);
    cout << txt;
    if (firstLine)
    {
        cout << endl;
    }
    ss_setTextColor(hConsole, defaultColor);
};
void printBingoResults(string txt, int color, bool needSpace)
{
    string spacing = needSpace ? "  " : " ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int defaultColor = 7;

    ss_setTextColor(hConsole, color);

    cout << spacing << txt;

    ss_setTextColor(hConsole, defaultColor);
};

class BingoBoard
{
public:
    BingoBoard(int boardID)
    {
        this->boardID = boardID;
    };
    int getID()
    {
        return this->boardID;
    };
    void addLine(string line, int id) // id to change txt color
    {
        /**
         * ? "(\\) or (\)" = escape sequence (chars w meaning that isnt literal)
         * ? "\\s*" = consume zero or more whitespace char then..
         * ? "\\s" = consume one whitespace char (space" ",tab"  ",new line"\n") then..
         * ? ("([0-9]+)") = 1 column, search range 0-9
         * ? ("\\s*([0-9]+)\\s*") = search 1 column for range 0-9, consume whitespace char
         * ? ("\\s*([0-9]+)\\s*([0-9]+)\\s*") = search 2 columns for range 0-9 consume whitespace char
         */
        const regex rx("\\s*([0-9]+)\\s*\\s*([0-9]+)\\s*\\s*([0-9]+)\\s*\\s*([0-9]+)\\s*\\s*([0-9]+)\\s*");
        smatch sm; // match = match_results<string::const_iterator>;

        if (regex_search(line, sm, rx)) // search for regex(rx) match(sm) in target text(line)
        {
            vector<int> row;
            vector<bool> rowSelections;
            for (int i = 1; i < sm.size(); i++)
            {
                string matchString = sm[i].str(); // convert matches in line to string
                row.push_back(stoi(matchString));
                rowSelections.push_back(false);
            }
            board.push_back(row);                //<- push this info into a vector of a vector
            selections.push_back(rowSelections); //<-
        }
        currentRow += 1;
    };
    bool checkNumber(int checkNum)
    {
        bool found = false;

        for (auto row = board.begin(); row != board.end(); row++) // "row" is a vector iterator
        {
            for (auto value = (*row).begin(); value != (*row).end(); value++)
            {
                //*  In the above 'for loop'..
                //                  THIS WOULD BE WRONG------->>//?  '*row.begin();'   would amount to  '*(row.begin());'
                //                                                            because the "." operator has precedence over the unary operator(*)
                //
                //                  THIS WOULD ALSO BE WRONG-->>//? '(*row)->begin()' because....
                //                                           ...'->' is for accessing object member variables and methods via //* pointer to object
                //                                        ..and '.' is for accessing object member variables and methods via //* object instance
                if ((*value) == checkNum)
                {
                    int rowIndex = distance(board.begin(), row);    // distance from row(0) to row(x)
                    int colIndex = distance((*row).begin(), value); // distance from row-instance[0] to value
                    selections[rowIndex][colIndex] = true;
                    found = true;
                    /**
                     *
                     *
                     **   ▁▁▁BINGO BOARD▁▁▁▁
                     *    | 22 13 17 11  0 | <- Row 0
                     *    |  8  2 23  4  7 | <- Row 1
                     *    | 21  9 14 16  5 | <- Row 2
                     *    |  6 10  3 18  5 | <- Row 3
                     *    |  1 12 20 15 19 | <- Row 4
                     **   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
                     **  e.g. MATCH FOR "7" FOUND
                     *
                     **   ▁▁▁BINGO BOARD▁▁▁▁
                     *    | 0              | <- Row 0
                     **   | 1  x  x  x  7  | <- Row 1*
                     *    | 2              | <- Row 2
                     *    | 3              | <- Row 3
                     *    | 4              | <- Row 4
                     **   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
                     **  ROW DISTANCE FROM (ROW 0) to (ROW 1) = 1
                     *
                     **   ▁▁▁BINGO BOARD▁▁▁▁
                     *    | 22 13 17 11  0 | <- ROW Distance = 0
                     *    |  8  2 23  4  7 | <- ROW Distance = 1
                     *    | 21  9 14 16  5 |                   2
                     *    |  6 10  3 18  5 |                   3
                     *    |  1 12 20 15 19 |                   4
                     **   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
                     **   COLUMN DISTANCE FROM (beginning of Row) to ("VALUE")
                     *
                     **   ▁▁▁BINGO BOARD▁▁▁▁
                     *    |              x |
                     **   |              7 |
                     *    |              x |
                     *    |              x |
                     *    |              x |
                     **   ▔▔▔0▔▔1▔▔2▔▔3▔▔4▔▔
                     *      0  1  2  3  4
                     **    COLUMN DISTANCES
                     *
                     *
                     */
                }
            }
        }
        if (found)
        {
            return hasWon();
        };

        return false;
    };
    int getSumOfUnmarkedNumbers() // this will be called on a winning board object instance
    {
        int sumNums = 0, numberCounter = 0;

        cout << endl
             << endl; // for printing boards

        for (auto row = selections.begin(); row != selections.end(); row++) // looping through rows
        {
            for (auto boolValue = (*row).begin(); boolValue != (*row).end(); boolValue++)
            {
                numberCounter++;   // keep track nums to print out boards
                if (!(*boolValue)) // number was picked
                {
                    int rowIndex = distance(selections.begin(), row);
                    int colIndex = distance((*row).begin(), boolValue);
                    int unmarked = board[rowIndex][colIndex];
                    sumNums += unmarked;

                    bool needsSpace = (unmarked < 9);
                    printBingoResults(to_string(unmarked), 8, needsSpace);
                }
                else
                {
                    int rowIndex = distance(selections.begin(), row);
                    int colIndex = distance((*row).begin(), boolValue);
                    int marked = board[rowIndex][colIndex];

                    bool needsSpace = (marked < 9);
                    printBingoResults(to_string(marked), 7, needsSpace);
                }
                if (numberCounter >= 5)
                {
                    cout << endl;
                    numberCounter = 0;
                }
            }
        }
        cout << endl
             << endl; // printing boards

        return sumNums;
    }

private:
    int boardID;
    int currentRow = 0;
    bool alreadyWon = false;
    vector<vector<int>> board;
    vector<vector<bool>> selections;

    bool hasWon()
    {
        if (alreadyWon) // if the board already won then get out of this function
        {
            return false;
        }
        for (auto row = selections.begin(); row != selections.end(); row++) // iterate through vector<vector<bool>>
        {
            if (checkRow(*row))
            {
                this->alreadyWon = true;
                return true;
            }
            for (int i = 0; i < 5; i++)
            {

                if (checkColumn(i))
                {
                    this->alreadyWon = true;
                    return true;
                }
            }
        }
        return false; // if either checkRow or checkColumn is true... we have a winner
    };

    bool checkRow(vector<bool> inputRow)
    {
        for (auto boolValue = inputRow.begin(); boolValue != inputRow.end(); boolValue++)
        {
            if (!(*boolValue))
            {
                return false;
            }
        }
        return true;
    };
    bool checkColumn(int columnIndex)
    {
        for (auto row = selections.begin(); row != selections.end(); row++)
        {
            if (!((*row)[columnIndex]))
            {
                return false;
            }
        }
        return true;
    };
};

void partOne()
{
    ifstream inputFile;
    inputFile.open("2021_04_input.txt");

    string line;
    string firstLine;
    bool firstLineRead = false;

    vector<BingoBoard *> boards;
    int boardNum = -1;

    while (getline(inputFile, line))
    {

        if (!firstLineRead)
        {
            firstLine = line;
            firstLineRead = true;
        }
        else
        {
            if (line.empty())
            {
                boardNum += 1;
                boards.push_back(new BingoBoard(boardNum));
            }
            else
            {
                boards[boardNum]->addLine(line, boardNum);
            }
        }
    }

    stringstream sStream(firstLine); // stream firstLine for simple int conversion

    for (int i; sStream >> i;) // stream int into "i"
    {
        for (auto bingoBoard = boards.begin(); bingoBoard != boards.end(); bingoBoard++) // loop through vector of class 'BingoBoard'
        {
            if ((*bingoBoard)->checkNumber(i))
            {
                int sum = (*bingoBoard)->getSumOfUnmarkedNumbers();
                cout << "Bingo Board # " << (*bingoBoard)->getID() << " " << sum * i;
            }
            if (sStream.peek() == ',')
            {
                sStream.ignore(); // ignore commas so stream reads other nums
            }
        }
    }
    return;
};

int main()
{
    partOne();

    return 0;
};
