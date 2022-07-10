#include <iostream>
#include <vector>

using namespace std;

const long long MOD = (int) 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> dp(n + 1);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (j <= k && i - j >= 0) {
            dp[i] += dp[i - j];
            dp[i] %= MOD; 
            j++;
        }
    }

    cout << dp[n] << endl;

    return 0;
}