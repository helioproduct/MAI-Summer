#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > dp(1, vector<int>(0, ));

int digitsum(int number)
{
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


int solve(int n, int s)
{   
    for (int i = 1; i < )

    return 1;
}

int main()
{
    int T;
    int N, S;
    cin >> T;

    while (T--) {
        cin >> N >> S;
        solve(N, S);
    }

    return 0;
}