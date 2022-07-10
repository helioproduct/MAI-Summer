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

// Кол-во копий за время t
int64_t function(int t, vector<int> &printers)
{
    int k = printers.size();
    int minTime = min(printers);
    int64_t copies = 1;

    if (k == 2) {
        copies += (t - minTime) / printers[0];
        copies += (t - minTime) / printers[1];
        return copies;
    }
    minTime = 10000;
    if (t < minTime) {

    }   


}

int main(void)
{   
    // n - кол-во копий
    // k - кол-во принтеров
    int n, k;
    cin >> n >> k;

    vector<int> printers(k);
    for (int i = 0; i < k; i++) {
        cin >> printers[i];
    }



    return 0;
}
