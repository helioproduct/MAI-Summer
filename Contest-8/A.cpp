#include <iostream>
#include <vector>

using namespace std;

const int64_t INF = 1e18;

struct wedge {
    int u, v;
    int64_t w;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    start--;

    vector<wedge> g;

    for (int i = 0; i < m; i++) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.push_back({u, v, w});
        g.push_back({v, u, w});
    }

    vector<int64_t> d(n, INF);
    d[start] = 0;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        flag = false;
        for (wedge elem : g) {
            int u = elem.u;
            int v = elem.v;
            int64_t w = elem.w;

            if (d[u] + w < d[v]) {
                flag = true;
                d[v] = d[u] + w;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (flag) {
        cout << "Negative cycle" << endl;
        return 0;
    }

    for (int64_t elem : d) {
        if (elem == INF) {
            elem = -1;
        }
        cout << elem << ' '; 
    }

    cout << endl;

    return 0;
}