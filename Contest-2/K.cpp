#include <iostream>
#include <vector>
#include <set>

using namespace std;


int median(multiset<int>& data)
{
    int n = data.size();
    int median = 0;

    auto iter = data.cbegin();
    advance(iter, n / 2);

    if (n % 2 == 0) {
        const auto iter2 = iter--;
        median = int(*iter + *iter2) / 2; 
    }
    else
        median = *iter;

    return median;
}


int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    multiset<int> prefix;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        prefix.insert(a[i]);
        cout << median(prefix) << endl;
    }

    return 0;
}