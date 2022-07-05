#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int count = 0;
    int index;

    cout << endl;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            auto it = upper_bound(a.begin() + j, a.end(), a[i] + a[j]);
            index = it - a.begin();
        }
    }

    cout << count << endl;

    return 0;
}