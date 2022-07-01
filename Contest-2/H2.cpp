#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, a, m, k, mod;
    cin >> n;
    cin >> a >> m >> k >> mod;
    
    vector <int> v(mod);
    for (int i = 0; i < n; ++i){
        v[a % mod]++;
        a = (a * m + k) % mod;
    }

    int count = 0;
    int s = 0;

    for (int i = 0; i < mod; i++){
        for (int j = 0; j < v[i]; j++){
            s += (++count * i);
            s %= ((int)1e9 + 7);
        }
    }
    cout << s;
	return 0;
}