#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> l(n);

    for (int i = 0; i < n; i++)
        cin >> l[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int c = j + 1; c < n; c++)
                if (l[c] < l[i] + l[j])
                    cout << l[i] << " " << l[j] << " " << l[c] << endl;
                    
    cout << ans;

    return 0;
}