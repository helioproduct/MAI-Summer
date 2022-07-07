#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, answer = 0, n1, i;
    cin >> n;
    n1 = n;
 
    vector<int> a(n);
    while (n1 != 0)  {
        cin >> i;
        a.push_back(i);
        n1 -= 1;
    }

    sort(a.begin(), a.end());
 
    int l_ = a.size() - 1;
 
    for (int i = 0, g = a.size() - 2; i < g; ++i)    {
        int l = i + 1;
        int r = a.size() - 1;
 
        while (l < l_)
        {
            int tx = a[i] - a[l];
            while (r > l && a[r] <= tx) --r;
            if (l >= r) break;
            answer += r - l;
            l++;
        }
    }
    cout << answer;
}
