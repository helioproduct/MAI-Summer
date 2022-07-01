#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool isnumber(string inString)
{
    for (char c : inString)
        if (!isdigit(c))
            return false;
    return true;
}


int main()
{
    string s;
    stack<long long> numbers;
    long long a, b;

    while (cin >> s) {
        if (isnumber(s)) {
            numbers.push(stoi(s));
        }
        else {
            b = numbers.top();
            numbers.pop();
            a = numbers.top();
            numbers.pop();
            
            if (s == "*") {
                numbers.push(a * b);
            }
            if (s == "+") {
                numbers.push(a + b);
            }
            if (s == "-") {
                numbers.push(a - b);
            }
        }

    }

    cout << numbers.top();

    return 0;
}