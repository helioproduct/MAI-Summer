#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    int n, k, m, danger;
    cin >> n >> k >> m;

    vector<int> dp(n + 1, 0);
    
    for(int i = 0; i < m; i++){
        cin >> danger;
        dp[danger] = -1; 
    }
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1)
            continue;

        int j = 1;
        while (i - j >= 0 && j <= k) {
            if (dp[i - j] == -1) {
                continue;
            }
            dp[i] += dp[i - j];
            dp[i] %= MOD;
            j++;
        }
    } 

    cout << dp[n] << endl;

    return 0;
}
