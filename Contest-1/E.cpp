#include <iostream>
#include <string.h>

using namespace std;

int holeCount(char digit)
{
    switch (digit)
    {
    case '0':
        return 1;
    case '1':
        return 0;
    case '2':
        return 0;
    case '3':
        return 0;
    case '4':
        return 1;
    case '5':
        return 0;
    case '6':
        return 1;
    case '7':
        return 0;
    case '8':
        return 2;
    case '9':
        return 1;
    }
    return 0;
}

int main()
{
    int count = 0;

    string input;
    cin >> input;


    for (char c : input) {
        count += holeCount(c);
    }

    cout << count;

    return 0;
}