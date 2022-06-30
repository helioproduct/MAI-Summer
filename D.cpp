#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, F;
    long long MOD = 1e9 + 7;

    F = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        F *= i;
        F = F % MOD;
    }

    cout << F;

    return 0;
}