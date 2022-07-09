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
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie(NULL);

    string t, p;
    cin >> t >> p;

    string s = t + "$" + p;
    vector<int> z = z_func(s);

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (z[i] == p.size()) {
            count++;
        }
    }

    if (count != 0) {
        cout << "TAK\n" << count << endl;
    } else {
        cout << "NIE" << endl;
    }

    return 0;
}