#include <iostream>
#include <vector>

using namespace std;

// vector print function
void print_vector(vector <long long> v) 
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    // input vector
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l, r;
    while (1) {
        cin >> l >> r;
        if (l == 0 && r == 0) break;
        l--; r--;
        // Reversing a subarray from l to r
        while (l < r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    // result output
    print_vector(a);
    return 0;
}