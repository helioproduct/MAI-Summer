#include <iostream>
#include <vector>

using namespace std;

int bubble()
{
    int n, x;
    cin >> n;
    vector<int> ar;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ar.push_back(x);
    }

    int count = 0;
    bool was = true;

    while (was) 
    {
        was = false;
        for (int i = 1; i < n; i++) 
        {
            if (ar[i - 1] > ar[i]) 
            {
                swap(ar[i - 1], ar[i]);
                count++;
                was = true;
            }
        }
    }

    return count;
}

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) 
    {
        cout << bubble();
        if (i != T - 1) {
            cout << "\n";
        }
    }
    return 0;
}