#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n;

    multiset<int> s;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    int first, second;
    while (s.size() > 1) {
        first = *s.begin();
        s.erase(s.find(x));

        second = *s.begin();
        s.erase(s.find(x));

        s.insert(first + second);

        cout << first << " " << second << endl;
    }
    return 0;
}