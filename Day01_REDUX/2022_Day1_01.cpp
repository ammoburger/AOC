#include "C:\Users\Spencer\projects\AOC\FunctionLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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

class Elf
{

public:
    Elf(int elfID)
    {
        this->elfID = elfID;
    };

    int getID()
    {
        return this->elfID;
    };

    void addFood(string line, int id)
    {
        int calories = stoi(line);
        foodCalories.push_back(calories);
    };

    int getSumOfCalories(int elfID)
    {
        int total = 0;
        for (int i = 0; i < foodCalories.size(); i++)
        {
            total += foodCalories[i];
        }
        return total;
    };

private:
    int elfID;
    vector<int> foodCalories;
    vector<vector<int>> totalCalories;

    void sumOfCalories(vector<int> calories)
    {
        int totalCal = 0;
        for (int i = 0; i < foodCalories.size(); i++)
        {
            totalCal += foodCalories[i];
        }
    }
};

void findWinningElf()
{
    ifstream inputFile;
    inputFile.open("2022_01_input.txt");

    string line;
    vector<Elf *> elves;
    int elfNumber = -1;

    bool firstLineRead = false;

    while (getline(inputFile, line))
    {

        if (!firstLineRead || line.empty())
        {
            elfNumber += 1;
            elves.push_back(new Elf(elfNumber));

            firstLineRead = true;
        }

        if (!line.empty())
        {
            elves[elfNumber]->addFood(line, elfNumber);
        }
    }

    int mostCalories = 0;
    int currentElfID = 0;

    for (auto elf : elves)
    {
        currentElfID = elf->getID();
        int sum = elf->getSumOfCalories(currentElfID);
        if (sum > mostCalories)
        {
            mostCalories = sum;
        }
    }
    printColorText("Elf# ", 4, false);
    printColorText(to_string(currentElfID), 2);
    printColorText(" wins with ", 4);
    printColorText(to_string(mostCalories), 2);
    printColorText(" calories!", 2);
}

int main()
{
    findWinningElf();
};