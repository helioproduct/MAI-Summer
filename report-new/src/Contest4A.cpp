#include <iostream>
#include <vector>

using namespace std;

// function for printing vector in one line
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // fast input
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // vecotor for containing prefix sum
    vector<long long> pref(n);
    pref[0] = a[0];

    for (int j = 0; j < n; j++) {
        pref[j] = pref[j - 1] + a[j];
    }

    // number of queris
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        // output query result
        cout << pref[r] - pref[l - 1] << endl;
    }
    return 0;
}