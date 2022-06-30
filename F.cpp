#include <iostream>

using namespace std;

int fib(long long number)
{
    if (number == 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }

    long long prev1 = 0;
    long long prev0 = 1;
    long long temp;
    long long next = 1;


    int count = 1;

    while (next <= number) {

        if (next == number) {
            return count;
        }
        
        temp = next;
        next = prev0 + prev1;
        prev1 = prev0;
        prev0 = next;
        count++;

    }

    return -1;
}



int main()
{
    long long number;
    cin >> number;

    cout << fib(number);

    return 0;
}