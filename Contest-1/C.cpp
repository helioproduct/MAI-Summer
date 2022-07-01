#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    
    int n1, n2;
    cin >> n1 >> n2;

    vector<char> str1(n1);
    vector<char> str2(n2);

    for (int  i = 0; i < str1.size(); i++)
        cin >> str1[i];
    
    for (int i = 0; i < str2.size(); i++) 
        cin >> str2[i];

    int point1 = 0;
    int point2 = str2.size();
    int ch = 0;
    bool isTrue = false;
 
    for (int i = 0; i < str1.size() - str2.size() + 1; i++) {
        isTrue = true;
        for (int j = 0; j < str2.size(); ++j)
            if (str1[j + point1] != str2[j])
                isTrue = false;

        if (isTrue)
            ch++;

        point1++;
    }
    cout << ch;
}