#include <iostream>
#include <vector>

using namespace std;

const long long MOD = (int) 1e9 + 7;

int main()
{
    int l, r;
    cin >> l >> r;
    vector<long long> dp(r + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 1; i <= r; i++) {

        for (int j = 2 * i; j <= r; j += i) {
            dp[j] += dp[i];
            dp[j] %= MOD;
        }

    }
    long long sum = 0;
    for (int i = l; i <= r; i++) {
        sum += dp[i];
        sum %= MOD;
    }
    cout << sum << endl;

    return 0;
}