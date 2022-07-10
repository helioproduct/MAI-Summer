#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    string a;
    string b;
    cin >> a >> b;
    vector<vector<int64_t>> dp(a.size() + 1, vector<int64_t>(b.size() + 1, 0));    

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;
    return 0;
}