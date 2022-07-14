#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n1, n2;
    cin >> n1 >> n2;

    // first string
    vector<char> str1(n1);
    // second string
    vector<char> str2(n2);

    // first string input
    for (int  i = 0; i < str1.size(); i++) {
        cin >> str1[i];
    }
    // second string input
    for (int i = 0; i < str2.size(); i++) {
        cin >> str2[i];
    }

    int p1 = 0, ch = 0;
    int p2 = str2.size();
    bool flag = false;
 
    // direct search
    for (int i = 0; i < str1.size() - str2.size() + 1; i++) {
        flag = true;
        for (int j = 0; j < str2.size(); ++j)
            if (str1[j + p1] != str2[j])
                flag = false;

        if (flag) {
            ch++;
        }
        p1++;
    }
    // result output
    cout << ch << endl;
    return 0;
}