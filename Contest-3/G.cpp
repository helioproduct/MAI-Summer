#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> dp(n + 1, INT_MAX);

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {

        if (dp[i + 1] + i + 1 < dp[i]) {
            dp[i] = dp[i + 1] + i + 1;
        }

        if (i * 3 <= n) {
            dp[i] = min(dp[i * 3] + i * 3, dp[i]);
        }

        if (i * 2 <= n) {
            dp[i] = min(dp[i * 2] + i * 2, dp[i]);
        }
    }

    cout << dp[1] << endl;  

    return 0;
}