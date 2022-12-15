//* =============================================================================== *//
//?                                     More ones...
//?     00100
//      11110
//      10110
//      10111
//      10101
//?     01111
//?     00111
//      11100
//      10000
//      11001
//      ?00010
//      ?01010
//! OXYGEN
//* =============================================================================== *//
//
//?                                  Second bit has more zeros...
//      10110 //*   1 (0) 110
//      10111 //*   1 (0) 111
//      10101 //*   1 (0) 101
//      10000 //*   1 (0) 000
//
//! OXYGEN
//* =============================================================================== *//
//
//?                                  Third bit has more ones...
//      10110  //*   10 (1) 10
//      10111  //*   10 (1) 11
//      10101  //*   10 (1) 01
//
//! OXYGEN
//* =============================================================================== *//
//
//?                                   Fourth bit has more ones...
//      10110  //*   101 (1) 0
//      10111  //*   101 (1) 1
//
//! OXYGEN
//* =============================================================================== *//
//
//?                                  Fifth bit has more ones...
//      10111  //*   101  1 (1)
//
//! OXYGEN
//* =============================================================================== *//

? string.find() will look for the first occurence of specified character in the string

    ? Delimiter - unique character that indicates beginning or end of string,
    statement, or function

                           !*Example Primary Expressions 100 // literal
                           'c'                               // literal
                           this                              // in a member function, a pointer to the class instance
                           ::func                            // a global function
                           ::operator+                       // a global operator function
                           ::A::B                            // a global qualified name
                           (i + 1)                           // a parenthesized expression

                           !*argv
                           -
                           argument vector * !argc - argument count

                   ? cin.eof() - tests for end - of - file

                         !*vector(c++) -
                         dynamic arrays that store data.Unlike arrays which are static in nature
                         EXAMPLE
                   : vector<object_type> variable_name;

?     push_back(): 
 The function pushes the elements into a vector from the back. If the type of object passed as a parameter in the push_back() is not same as that of the vector an exception is thrown.

?     assign(): 
It assigns a new value to the vector elements by replacing old ones.

?     pop_back(): 
 function is used to pop or remove elements from a vector from the back. It reduces the size of the vector by one element.

?     insert(): 
This function inserts new elements before the element before the position pointed by the iterator. We can also pass a third argument count, that counts the number of times the element is to be inserted before the pointed position.

?     erase(): 
 function is used to remove elements from a container from the specified position or range. We can either pass the position of the specific elements needs need to remove or we can pass the starting point and endpoint of a range of elements. 

?     swap(): 
 function is used to swap the contents of one vector with another vector of the same type. Sizes may differ.

?     clear(): 
 function is used to remove all the elements of the vector container

*! eof()
Rules for EOF: Use a while loop for getting data from an input file stream.  A for loop is desirable only when you know the exact number of data items in the file, which we do not know.


//
TERMINAL
*! CD = Class Diagram
*! PS = PowerShell
//


*! STL - Standard Template Library (template classes for functions, data structs, lists, arrays etc.)
