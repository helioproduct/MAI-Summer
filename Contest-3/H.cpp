#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> dp(n, 1);

        int mx = 1;
        int mx_index = 0;

        for (int i = 1; i < n; i++) {
            int local_mx = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] < a[i]) {
                    if (dp[j] > local_mx) {
                        local_mx = dp[j];
                    } 
                }
            }
            dp[i] += local_mx;

            if (dp[i] > mx) {
                mx = dp[i];
                mx_index = i;
            }
        }

        vector<int> indexes;

        cout << mx << endl;

        while (dp[mx_index] != 1) {
            if (dp[mx_index] == mx) {
                indexes.push_back(mx_index + 1);
                mx--;
            }

            mx_index--;
        
            if (dp[mx_index] == 1) {
                indexes.push_back(mx_index + 1);
            }
        }

        for (int i = indexes.size() - 1; i >= 0; i--) {
            cout << indexes[i] << " ";
        }
        cout << endl;

        T--;
    }

    return 0;
}