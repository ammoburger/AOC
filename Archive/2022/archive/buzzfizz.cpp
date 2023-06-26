#include <iostream>
#include <string>

using namespace std;

int main()
{
    for (int j = 1; j <= 100; j++)
    {
        if (j % 5 == 0 && j % 3 == 0) // JizzFuzz
        {
            cout << "JizzFuzz\n";
        }
        else if (j % 5 == 0) // Fuzz
        {
            cout << "Fuzz\n";
        }
        else if (j % 3 == 0) // Jizz
        {
            cout << "Jizz\n";
        }
        else
        {
            cout << j << "\n";
        }
    }
}