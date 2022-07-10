#include <iostream>
#include <vector>

using namespace std;
using graph = vector< vector<int> >;

// depth-first search
void dfs(int v, const graph &g, vector<int> &depth, int &curr)
{
    if (depth[v] != -1)
        return;
    depth[v] = ++curr;
    for (int u: g[v]) {
        dfs(u, g, depth, curr);
    }
}

int main() 
{
    // fast input
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    
    graph g(n);
    // input graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // vector that contains depht of each vertex
    vector<int> depth(n, -1);
    int curr = -1;
    
    dfs(k, g, depth, curr);
   
    // result output
    for (int d : depth) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}