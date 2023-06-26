#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string line;
    while (!cin.eof())
    {
        getline(cin, line);

        if (cin.fail())
        {

            break;
        }
        int test = 0;
        cin >> test;
        if (cin.fail())
        {
            cout << "error";
        }
        cout << "Hello, to continue, press y/n ";
    }
}