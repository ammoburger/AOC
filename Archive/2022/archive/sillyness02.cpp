

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string source;
    string token;

    vector<string> letters;
    source = "1-3,12-66";

    stringstream stream(source); // source is an object of stringstream that references the source string

    while (getline(stream, token, ',')) // stream used to store the token "," = delimiter
    {
        letters.push_back(token);
    }
    vector<int> numbers;
    string left = letters[0];
    stringstream leftstream(left);
    while (getline(leftstream, token, '-'))
    {
        numbers.push_back(stoi(token));
        cout << numbers[0];

        return 0;
    }
}

// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <string>
// using namespace std;

// int main()
// {
//     string source, token; // declare string variables

//     source = "20-25,15-31";
//     // SPLIT on comma: ["20-25", "15-31"]

//     stringstream stream(source); // ss is an object of stringstream that references the S string

//     vector<string> words;

//     while (getline(stream, token, ',')) // str used to store the token string while ' ' whitespace is used as delimiter
//         words.push_back(token);

//     vector<int> leftnumbers;
//     string left = words[0];
//     stringstream leftstream(left);

//     while (getline(leftstream, token, '-'))
//         leftnumbers.push_back(stoi(token));

//     cout << leftnumbers[0] << endl;
//     cout << leftnumbers[1] << endl;

// use while loop to check the getline() function condition
// getline(stream, token, ',');
// string anus = token;
// cout << token;

// getline(stream, token, '-');
// string weeners = token;
// cout << weeners;

// getline(stream, token, ',');
// string right = token;
// cout << left << endl;

//     return 0;
// }