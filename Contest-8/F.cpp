#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
using item = pair<int, int>;

const int INF = 1e5 + 1;

struct wedge {
    int u, v;
    int w;
};

using wgraph = vector< vector<wedge> >;

vector<int> dijkstra(int start, const wgraph &g)
{
    int n = g.size();
    vector<bool> visited(n);
	
    vector<int> d (n, INF),  p (n);
	d[start] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, start));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].u,
				len = g[v][j].v;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push (make_pair (-d[to], to));
			}
		}
	}
    return d;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    // wgraph g(n);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int aij;
    //         cin >> aij;
    //         g[i].push_back({i, j, aij});
    //         g[i].push_back({i, j, aij});
    //     }
    // } 

    vector< vector<int> > d(n, vector<int>(n, INF)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            int64_t w;
            cin >> w;
            d[i][j] = w;
        }
    }

    for (int k=0; k<n; ++k)
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (d[i][k] < INF && d[k][j] < INF)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    

    while (q)
    {
        int s;
        cin >> s;

        s--;

        for (int i = 0; i < n; i++) {
            if (d[s][i] == INF)
                d[s][s] = -1;
            cout << d[s][i] << " ";
        } cout << "\n";

        q--;
    }

    return 0;
}