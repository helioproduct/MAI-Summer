#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>


using namespace std;

const long long e = 1000000000 + 7;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, a0;

    long long max1 = 0;
    long long max2 = -1;

    cin >> n >> a0;
    
    long long t = a0 % e;

    for (int i = 0; i < n; i++){
        t *= 5;
        t %= e;

        if (t > max1) {
            max2 = max1;
            max1 = t;
        } else if (t > max2) {
            max2 = t;
        }
    }
    cout << max2 << " " << max1;

	return 0;
}