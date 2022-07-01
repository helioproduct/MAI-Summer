#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{   
    int n;
    cin >> n;

    set<string> words;
    string word;
    
    for (int i = 0; i < n; i++) {
        cin >> word;
        sort(word.begin(), word.end());
        words.insert(word);
    }

    cout << words.size();

    return 0;
}