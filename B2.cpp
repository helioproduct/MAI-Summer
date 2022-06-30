#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <long long> v) 
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
}

int main()
{
    int n;
    long long temp;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l, r;

    while (1) {
        cin >> l >> r;
        if (l == 0 && r == 0) break;
        l--; r--;

        while (l < r) {
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
    }

    printVector(a);
    
    return 0;
}