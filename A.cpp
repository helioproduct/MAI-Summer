#include <iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    long long sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    cout << sum;
    
    return 0;
}