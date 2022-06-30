#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& a) {
    sort(a.begin(), a.end());
    std::cout << a.size() << " ";
    for (int i = 0; i < a.size(); i++)
    {
        if (i == a.size() - 1) std::cout << a[i];
        else std::cout << a[i] << " ";
    }
}

int main(void)
{
    int n, mn = 0, mx = 0;
    cin >> n;

    vector<int> a(n);
    vector<int> ansMn, ansMx;
 
    for (auto &v: a) {
        cin >> v;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            ansMn.push_back(i + 1);
        }
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ansMx.push_back(i + 1);
        }
    }


    if (n == 1) {
        ansMn.push_back(1);
        ansMx.push_back(1);
    } 
    else {
        if (a[0] < a[1]) {
            ansMn.push_back(1);
        }

        if (a[0] > a[1]) {
            ansMx.push_back(1);
        }

        if (a[n - 1] < a[n - 2]) {
            ansMn.push_back(n);
        }

        if (a[n - 1] > a[n - 2]) {
            ansMx.push_back(n);
        }

        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[mx]) {
                mx = i;
            }
        }

        for (int i = 1; i < n; ++i)
        {
            if (a[i] < a[mn]) {
                mn = i;
            }
        }
    }

    print(ansMn);
    std::cout << endl;
    print(ansMx);
    std::cout << endl << mn + 1 << " " << mx + 1;

    return 0;
}
