#include <iostream>
#include <vector>

using namespace std;

// Функция печати вектора
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

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l, r;
    while (1) {
        cin >> l >> r;
        if (l == 0 && r == 0) break;
        l--; r--;
        // Разворот подмассива от l до r
        while (l < r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    print_vector(a);
    
    return 0;
}