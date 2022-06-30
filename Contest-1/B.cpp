#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    int p1, p2; 
    int ch1, ch2;
    int temp = 0;

    while (p1 != 0 && p2 != 0)
    {
        ch1 = p1 - 1;
        ch2 = p2 - 1; 
        while(ch1 < ch2)
        {
            temp = a[ch1];
            a[ch2] = temp;
            ch1++;
            ch2--;
        }
        cin >> p1 >> p2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}