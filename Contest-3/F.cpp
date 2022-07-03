#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printMatrix(vector<vector<int>> a) 
{
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;


    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<int>> value(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> value[i][j];
        }
    }

    dp[0][0] = value[0][0]; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i - 1 >= 0) {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j] + value[i][j]);
            }

            if (j - 1 >= 0) {
                dp[i][j] = max(dp[i][j],
                               dp[i][j - 1] + value[i][j]);
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - 1] + value[i][j]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}