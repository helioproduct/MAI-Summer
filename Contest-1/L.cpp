#include <iostream>
#include <string>

using namespace std;

const long long MOD = (long long) 1e15;


void formatPrint(long long first, long long second) {
    string s = to_string(second);

    int size = 15 - s.size();

    for (int i = 0; i < size; i++) {
        s = s.append("0");
    }

    cout << first << "." << s << endl;
}

int main()
{
    long long x = 0; // Целая часть
    long long y = 0; // Дробная часть

    string number;

    while (cin >> number) {
        int dot = number.find('.');

        long left = stoll(number.substr(0, dot));
        long right = stoll(number.substr(dot + 1));

        x += left;
        y += right;
    }

    x += y / MOD;
    y %= MOD;

    // cout << x << "." << y << endl;
    formatPrint(x, y);  

    return 0;
}