#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a;

    cin >> n;

    multiset<int> s;
    for(int i = 0; i < n; i++){
        cin >> a;
        s.insert(a);
    }
    while(s.size() > 1){
        int y, x = *s.begin();
        s.erase(s.find(x));
        y = *s.begin();
        s.erase(s.find(y));
        s.insert(x + y);
        cout << x << " " << y << '\n';
    }
	return 0;
}