#include <iostream>

using namespace std;

int main()
{
    double x;
    double sum = 0; 

    while (cin >> x) {
        sum += x;
    }
    
    cout.setf(ios::fixed);
    cout.precision(15);
    cout << fixed << sum;

    return 0;
}