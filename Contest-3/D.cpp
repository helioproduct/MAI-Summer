#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> cost(n + 1);

    cost[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> cost[i];
    }
    cost[n] = 0;
    
    vector<long long> dp(n + 1, INT_MAX);
    dp[0] = 0;

    vector<int> prev(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int j = 1;
        int m;

        for (j = 1; j <= k; ++j) {
            if (i - j < 0) {
                break;
            } 

            if (dp[i - j] < dp[i]) {
                dp[i] = dp[i - j];
                m = i - j;
            }
        }
        dp[i] += cost[i];
        prev[i] = m;
    }

    cout << dp[n] << endl;

    vector<int> path;
    int u = n;
    
    while (prev[u] != u) {
        path.push_back(u);
        u = prev[u];
    }

    path.push_back(0);
    
    cout << path.size() << endl;

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}
