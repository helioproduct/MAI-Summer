#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long hashit(vector<int> v, int n, int mod)
{
    long long result = 0;

    for (int i = 0; i <= n - 1; i++) {
        result += (i + 1) * v[i] * (mod * (1e9 + 7));
    }
    return result;
}


int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, m, k, mod;

    cin >> n;
    cin >> a >> m >> k >> mod;

    vector<int> v(n);

    for (int i = 0; i < n; ++i){
        v[i] = a;
        a = (a * m + k) % mod;
    }

    sort(v.begin(), v.end());

    cout << hashit(v, n, mod) << endl;
    

    return 0;
}