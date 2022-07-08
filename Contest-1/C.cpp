#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n1, n2;
    cin >> n1 >> n2;

    // Первая строка
    vector<char> str1(n1);
    // Вторая строка
    vector<char> str2(n2);

    for (int  i = 0; i < str1.size(); i++) {
        cin >> str1[i];
    }
    
    for (int i = 0; i < str2.size(); i++) {
        cin >> str2[i];
    }

    int p1 = 0;
    int p2 = str2.size();
    int ch = 0;
    bool flag = false;
 
    // Прямой поиск
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
    cout << ch << endl;
}