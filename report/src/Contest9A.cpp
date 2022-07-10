#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z_func(const string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] >= r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main(void)
{
    string s;
    cin >> s;

    vector<int> z = z_func(s);
    for (int i = 0; i < s.size(); i++) {
        cout << z[i] << " ";
    }
    cout << endl;

    return 0;
}