#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int l, r;
    long long cnt = 0;

    vector<pair<int, int>> v; 

    for (int i = 0; i < n; i++) {
        cin >> l >> r;

        v.push_back(make_pair(l, +1));
        v.push_back(make_pair(r, -1));      
    }
        
    sort(v.begin(), v.end());

    // Самая правая точка : cnt = 0
    int lp = -1;
    int last_lp = v[0].first;
    int answer = 0;

    for (pair p : v) {
        cnt += p.second;
        if (cnt == 0) {
            answer += (p.first - last_lp + 1);
            last_lp = lp;
            lp = p.first;
            cout << "new lp at: " << lp << endl;
        }
    }

    if (lp == -1) {
        cout << v[v.size() - 1].first + 1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}