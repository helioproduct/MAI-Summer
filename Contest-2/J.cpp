#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int index;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto start = a.begin() + j + 1;
            int sum = a[i] + a[j];
            auto it = upper_bound(start, a.end(), sum);


            if (it == a.end()) {
                cout << "end\n";
            }

            index = it - a.begin(); 
            count += index - j - 1;
        }
    }

    cout << count << endl;

    return 0;
}