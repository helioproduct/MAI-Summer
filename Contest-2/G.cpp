#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while (a.size() != 1) {
        cout << a[0] << " " << a[1] << endl;

        int y = a[0] + a[1];

        auto it = lower_bound(a.begin(), a.end(), y);
        a.insert(it, 1, y);

        a.erase(a.begin());
        a.erase(a.begin());
    }

    return 0;
}