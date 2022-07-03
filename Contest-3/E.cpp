#include <iostream>
#include <vector>

using namespace std;

const long long MOD = (int)1e9 + 7;

void printMatrix(vector<vector<int64_t>> a) 
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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int64_t>> a(n + 1, 
                              vector<int64_t>(m + 1, 0));

    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        a[x][y] = -1;
    }

    a[0][0] = 1;    


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (a[i][j] == -1) {
                continue;
            }

            if (i - 1 >= 0 && a[i - 1][j] != -1) {
                a[i][j] += a[i - 1][j];
                a[i][j] %= MOD;
            }

            if (j - 1 >= 0 && a[i][j - 1] != -1) {
                a[i][j] += a[i][j - 1];
                a[i][j] %= MOD;
            }

        }
    }

    cout << a[n][m];

    return 0;
}