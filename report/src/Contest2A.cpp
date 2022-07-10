#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // input 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sorting vector
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] + 1) {
            // result output
            cout << "Scammed";
            return 0;
        }
    }
    // result output
    cout << "Deck looks good";
    return 0;
}