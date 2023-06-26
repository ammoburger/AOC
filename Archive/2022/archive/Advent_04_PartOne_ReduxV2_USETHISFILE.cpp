#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;
int main()
{
    string line;
    ifstream inFile;
    inFile.open("04input.txt");

    const char delComma = ',', delDash = '-'; //* const char delimiters

    // Every line is:
    // 3-9,8-12
    // first, we split on ,
    // [3-9, 8-12]
    // then we split on -
    // [[3, 9], [8, 12]]

    int finalScore = 0;
    while (getline(inFile, line))
    {
        // line = 3-9,8-12 the first loop
        vector<vector<int>> ranges;

        stringstream linestream(line);
        string range;
        while (getline(linestream, range, delComma))
        {
            // range = 3-9 the first loop, then the second time range = 8-12

            // we need a container for the 3 and 9
            vector<int> currentRange;

            stringstream rangestream(range);
            string value;
            while (getline(rangestream, value, delDash))
            {
                // value = 3 the first loop, then 9.
                currentRange.push_back(stoi(value));
            }

            ranges.push_back(currentRange);
        }
        // vector<int> nums = [ 1, 2, 3 ];

        // nums[0] == 1;
        // nums[1] == 2;

        // vector<vector<int>> nums2 = [ [ 1, 2, 3 ], [ 4, 5, 6 ] ];

        // get 6

        // nums2[0] == [ 1, 2, 3 ]; // vec
        // nums2[1] == [ 4, 5, 6 ]; // vec
        // nums2[1][2] == 6;        // int

        // Either use the [] operator to get the first array, then use the [] operator to get the element of that array

        set<int> one;
        for (int i = ranges[0][0]; i <= ranges[0][1]; i++)
        {
            one.insert(i);
        }

        // OR bind the first array to a variable and use the [] operator on that variable

        set<int> two;
        vector<int> secondRange = ranges[1];
        for (int i = secondRange[0]; i <= secondRange[1]; i++)
        {
            two.insert(i);
        }

        if (includes(one.begin(), one.end(), two.begin(), two.end()) || includes(two.begin(), two.end(), one.begin(), one.end()))
        {
            finalScore++;
        }
    }

    cout << finalScore; // print final score
    return 0;
}
