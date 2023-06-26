#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream> // for file stream
#include <limits>

using namespace std;

template <typename T>
void print(T &vecOfElements, std::string delimeter = " , ")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}

std::fstream &GotoLine(std::fstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

char findBadge(string line1, string line2, string line3)
{
    for (auto &let1 : line1) // auto = whatever the type is, we'll use that
    {
        for (auto &let2 : line2)
        {
            for (auto &let3 : line3)
            {
                if (let1 == let2 && let2 == let3) //?  (1 == 2 == 3)
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
    int linecount = 0; // init counter
    int pFinalScore = 0;
    vector<string> lineGroup; // block of three lines with a shared unique priority

    fstream fileHandler; // Input file stream

    fileHandler.open("03_TEST_INPUT.txt", ios::in | ios::out);

    if (!fileHandler) // check if file open
    {
        cout << "File not open!";
        exit(1);
    }
    ////////////////////?
    ////!  WRITE   //////
    ////////////////////?
    getline(fileHandler, line);
    for (int i = 1; i <= 300; i++) // loop through 300 input lines
    {
        linecount++;
        if (linecount % 4 || linecount == 1) // if we got a group of 3 then increment the count
        {
            linecount++;
            GotoLine(fileHandler, i);
            string lineX;
            fileHandler >> lineX;
            cout << lineX << "\n\n\n";
        }
        else
        {
            cout << endl;
        }
    }

    fileHandler.seekg(ios::beg);

    ////////////////////?
    ////*  READ   //////
    ////////////////////?
    if (fileHandler.is_open())
    {
        fileHandler.seekg(ios::beg);
        while (getline(fileHandler, line))
        {
            string line;
            int linecount = 0;
            int pFinalScore = 0;
            vector<string> lineGroup;

            // ifstream myinput("cumload.txt"); // Input file stream

            map<char, int> priority; // Initialize container
            const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for (int i = 0; i < 52; ++i)
            {
                priority[letters[i]] = i + 1; // Assign priority to letters
            }

            if (fileHandler.is_open()) // input file open
            {
                while (getline(fileHandler, line))
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
                        pFinalScore += priority[badge];
                        lineGroup.clear();
                    }
                }
            }
            cout << pFinalScore;
            fileHandler.close();
        }
    }
    else
    {
        cout << "Unable to open file";
    }
}
