#include <iostream>
#include <vector>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> a(T);
    int x;

    for (int i = 0; i < T; i++)
    {
        cin >> x;
        a[i] = x;
    }

    for (int i = 0; i < a.size(); i++)
    {
        int S = a[i];

        int k5000 = S / 5000;
        S -= 5000 * k5000;

        int k1000 = S / 1000;
        S -= 1000 * k1000;

        int k500 = S / 500;
        S -= 500 * k500;

        int k200 = S / 200;
        S -= 200 * k200;

        int k100 = S / 100;
        S -= 100 * k100;

        if (i == a.size() - 1) {
            cout << k100 << " " << k200 << " " << k500 << " " << k1000 << " " << k5000;
        }
        else {
            cout << k100 << " " << k200 << " " << k500 << " " << k1000 << " " << k5000 << endl;
        }
    }
    
    return 0;
}