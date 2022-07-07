#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(double a, double base)
{
    int pw = log(a) / log(base);

    if (pow(3, pw) == a) {
        return log(a) / log(base);
    }

    return log(a) / log(base) + 1;
}

int main()
{
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << solve(N, 3) << endl;
    }
    return 0;
}