#include <windows.h>

int ss_addNumbers(int a, int b)
{
    return (a + b);
}

int ss_char2Int(char convert)
{
    return convert - '0';
}

void ss_setTextColor(HANDLE handl, int colorCode)
{
    // set the color of the terminal output color
    SetConsoleTextAttribute(handl, colorCode);
}
