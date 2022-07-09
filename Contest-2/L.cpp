#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int min(vector<int> &v) 
{
    int min = INF;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

// Количество копий за время t
int psi(int t, vector<int> &xeroxes)
{
    int total_time = min(xeroxes);
    for (int i = 0; i < xeroxes.size(); i++) {
        total_time += (t - min(xeroxes)) / xeroxes[i]; 
    }
    return total_time;
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> xeroxes(k);
    for (int i = 0; i < k; i++) {
        cin >> xeroxes[i];
    }
    psi(1, xeroxes);

    return 0;
}
