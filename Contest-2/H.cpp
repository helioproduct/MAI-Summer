#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const long long H = (long long) 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, a, m, k, mod;
    cin >> n >> a >> m >> k >> mod; 

    vector<int> count(mod, 0);

    for (int i = 0; i < n; i++) {
        count[a]++;
        a = (a * m + k) % mod;
    }

    long long sum = 0;

    int index = 0;

    for (int i = 0; i < mod; i++) {
        for (int j = 0; j < count[i]; j++) {
            sum += (index + 1) * i;
            sum %= H;            
            index++;
        }
    }

    cout << sum << endl;

    return 0;
}
