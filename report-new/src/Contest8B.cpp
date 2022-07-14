#include <iostream>
#include <vector>

using namespace std;

const int64_t INF = 1e18;

// weighted edge
struct wedge {
    int u, v;
    int64_t w;
};

int main(void)
{
    int n;
    cin >> n;
    vector<wedge> g;
    // table of distances between all vertices 
    vector< vector <int64_t> > d(n, vector<int64_t> (n, INF));
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
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    // result output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
