#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long x = 0; // Целая часть
    long long y = 0; // Дробная часть
    int dot;

    string number;
    string first;
    string second;
    
    while (cin >> number) {
        dot = number.find('.'); 
        first = number.substr(0, dot);
        second = number.substr(dot + 1, number.size());

        x += stoll(first.c_str());    
        y += stoll(second.c_str());
    }   


    long long temp = y;
    y %= (int) 1e15;
    x += (temp - y);

    cout << x << "." << y;


    return 0;
}