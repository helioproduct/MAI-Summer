#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int getValue(char c)
{
    if (48 <= c && c <= 57) {
        return c - 48;
    }
    return c - 87;
}

char getChar(int number)
{
    if (0 <= number && number <= 9) {
        return (char) (number + 48);
    }
    return (char) (number + 87);
}

string cc(string number, int from, int to)
{
    long long number10 = 0;

    for (int i = 0; i < number.size(); i++) {
        int pw = number.size() - i - 1;
        number10 += getValue(number[i]) * pow(from, pw);
    }

    string newNumber = "";

    if (number10 == 0) {
        return "0";
    }

    while (number10 > 0) {
        newNumber.push_back(getChar(number10 % to));
        number10 /= to;
    }
    reverse(newNumber.begin(), newNumber.end());
    return newNumber;
}


int main()
{
    int A, B;
    string number;

    cin >> A >> B >> number;
    cout << cc(number, A, B) << endl;
    
    return 0;
}