#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    multiset<int> a;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }


    for (int x : a)
        cout << x << endl;

    return 0;
}