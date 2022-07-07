#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using graph = vector< vector<int> >;

const int INF = 1e9;

void bfs(int start, const graph &g, vector<int> &d, vector<int> &p)
{   
    d[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    
    graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> d(n, INF);
    vector<int> p(n, -1);

    bfs(k, g, d, p);

    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            cout << -1 << " ";
        }
        else {
            cout << d[i] << " ";
        }
    }

    cout << endl;

    return 0;
}