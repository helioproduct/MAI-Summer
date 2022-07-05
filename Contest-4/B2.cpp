#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;


const int OPEN = -1;
const int CLOSE = 2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pii> events;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, OPEN});
        events.push_back({r + 1, CLOSE});
    }

    sort(events.begin(), events.end());

    int64_t lp = events[0].first - 1, cnt = 0, ans = 0;

    for (pii elem : events) {
        int xi = elem.first;
        int event = elem.second;
        if (event == OPEN) {
            cnt++;
        } else {
            cnt--;
        }

        if (cnt == 0) {
            ans += xi - lp - 1;
            lp = xi;
        }
    }

    cout << ans << endl;

    return 0;
}