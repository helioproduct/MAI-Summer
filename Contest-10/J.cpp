#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = (int) 1e9 + 7;

int hash(string s) {
    int result = 0;
    for(int i = 0; i < s.size(); ++i) {
        result = (result * 31 + s[i] - 'a' + 1) % MOD;
    }
    return result;
}


int main(void)
{

    return 0;
}