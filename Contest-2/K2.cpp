#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int a = 0;
    int n = 0;
    cin >> n;

    multiset <int> x;
    multiset <int> y;
    
    cin >> a;
    y.insert(a);
    cout << a << "\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        if (i % 2 == 1) {
            if (a <= *x.begin()){
                y.insert(a);
 
                cout << *y.rbegin();
            }
            else {
                y.insert(*x.begin());
                x.erase(x.find(*x.begin()));
                x.insert(a);
                cout << *y.rbegin();
            }
        }
        else {
            if (a >= *y.rbegin()){
                x.insert(a);
                cout << *y.rbegin();
            }
            else{
                x.insert(*y.rbegin());
                y.erase(y.find(*y.rbegin()));
                y.insert(a);
                cout << *y.rbegin();
            }
        }
        cout << '\n';
    }
}


