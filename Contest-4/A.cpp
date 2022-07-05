#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> pref(n);
    pref[0] = a[0];


    // O(n);
    for (int j = 0; j < n; j++) {
        pref[j] = pref[j - 1] + a[j];
    }

    cin >> q;

    // total = O(n + q)
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << pref[r] - pref[l - 1] << endl;
    }
    return 0;
}