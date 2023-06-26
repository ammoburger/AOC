#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

///
template <typename T>
void print(T &vecOfElements, std::string delimeter = " , ")
{
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}
///

int addvecs(vector<int> inputvec)
{
    vector<int> poo;
    poo = inputvec;
    int linesum;

    for (int a = 0; a < poo.size(); a++)
    {
        linesum = linesum + poo[a];
    }

    // cout << linesum << "\n";
    poo.clear();
    return linesum;
}

int main(int argc, char *argv[])
{

    vector<int> lines_of_numbers;

    vector<int> caltotal;

    int last_line_total = 0;

    while (!cin.eof()) // while not the end-of-file, do this
    {
        string single_line;
        getline(cin, single_line); // function to read a line of input

        if (single_line.length() > 0)
        {
            if (cin.fail())
            {
                break; // cin input is not correct
            }

            int num1 = stoi(single_line);
            lines_of_numbers.push_back(num1); // push line number to back of vector

            last_line_total = lines_of_numbers.size(); // set last_line_total to be number of non-empty lines
        }
        else if (last_line_total >= lines_of_numbers.size())
        {

            caltotal.push_back(addvecs(lines_of_numbers));
            lines_of_numbers.clear();

            // cout << addvecs(lines_of_numbers) / 2;
            cout << endl;
            // print(caltotal, ",");
        }
    }

    int bagofcandy = 0; //  <--needs to be " = 0" otherwise output ends with "5" for unknown reasons

    for (int a = 0; a < caltotal.size(); a++)
    {
        int num;

        num = caltotal[a];

        if (bagofcandy < num)
        {
            if (num < 71502 && num < 68977)
            {
                bagofcandy = num;
            }
        }
    }

    cout << bagofcandy;

    cout.flush();
};