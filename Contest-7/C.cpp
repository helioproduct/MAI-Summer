#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using graph = vector< vector<int> >;

bool dfs(int v, int u, const graph &g, vector<bool> &visited, 
									   vector<int> &path)
{
	if (visited[v]) {
		return false;
	}

	visited[v] = true;
	path.push_back(v);

	if (v == u) {
		return true;
	}

	for (int x : g[v]) {
		dfs(x, u, g, visited, path);
	}

	return false;
}


int main(void)
{
	int n, m;
	int u, v;
	cin >> n >> m >> u >> v;
	u--; v--;

	int a, b;
	graph g(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}	
	
	vector<bool> visited(n, false);
	vector<int> path;

	if (dfs(v, u, g, visited, path)) {
		cout << "found\n";
		reverse(path.begin(), path.end());
	
		for (int x : path) {
			cout << x << " ";
		}
	}

	return 0;
}

