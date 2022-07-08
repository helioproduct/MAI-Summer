#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;
using item = pair<int64_t, int>;

const int64_t INF = 1e18;

struct wedge {
    int u, v;
    int64_t w;
};

using wgraph = vector< vector<wedge> >;

vector<int64_t> dijkstra(int start, const wgraph &g,
                         vector<int> &prev)
{
    int n = g.size();
    vector<int64_t> d(n, INF);
    vector<bool> visited(n);
    set<item> pq;
    d[start] = 0;
    for (int i = 0; i < n; ++i) {
        pq.insert({d[i], i});
    }
    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (wedge elem : g[u]) {
            int v = elem.v;
            int64_t w = elem.w;
            if (d[u] + w < d[v]) {
                pq.erase({d[v], v});
                d[v] = d[u] + w;
                pq.insert({d[v], v});

                prev[v] = u;
            }
        }
    }
    return d;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, start;
    cin >> n >> m;
    start = 0;

    wgraph g(n);
    vector<int> prev(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        u--; v--;

        g[u].push_back({u, v, w});
        g[v].push_back({v, u, w});
    }

    vector<int64_t> d = dijkstra(start, g, prev);

    int current = n;
    current--;

    stack<int> ans;
    ans.push(current + 1);

    while (1) {
        current = prev[current];
        if (current == -1) {
            break;
        }
        ans.push(current + 1);
    }
    
    if (ans.size() == 1) {
        cout << -1 << endl;
        return 0;
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}