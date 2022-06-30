#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print(vector<int>& a)
{
    cout << a.size() << " ";
    for (int i = 0; i < a.size(); i++)
    {
        if (i == a.size() - 1) cout << a[i];
        else cout << a[i] << " ";
    }
}

int getValue(char& c)
{
    // Если с - число [0; 9]
    if (48 <= c && c <= 57) {
        return c - 48;
    }
    // Если маленькие буквы
    return c - 87;
}

string cc(long long n, int b)
{
    string nb;
    while (n > 0)
    {
        int ost = n % b;
        if (ost > 9) {
            char digit;
            digit = 87 + ost;
            string s = "";
            s.push_back(digit);
            nb.insert(0, s);

        } 
        else {
            nb.insert(0, to_string(ost));
        }
        n /= b;
    }
    return nb;
}



int main(void) {
    int a, b;
    string n;
    cin >> a >> b;
    cin >> n;

    if (n == "0") {
        cout << 0;
        return;
    }

    long long n10 = 0;

    for (int i = n.size() - 1; i >= 0; --i)
    {
        char c = n[i];
        int value = getValue(c);
        int pw = n.size() - i - 1;
        n10 += pow(a, pw) * value;
    }

    cout << cc(n10, b);

    return 0;
}
