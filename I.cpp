#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    float x1, y1, x2, y2;
    float x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if (x1 > x2) {
        swap(x1, x2);
    }

    if (x3 > x4) {
        swap(x3, x4);
    }

    if (y1 > y2) {
        swap(y1, y2);
    }

    if (y3 > y4) {
        swap(y3, y4);
    }

    float S = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);

    float xLeft;
    float xRight;

    float yDown;
    float yUp;

    if (x2 <= x3) {
        cout << S;
        return 0;
    } 
    else {
        xLeft = max(x1, x3);

        if (x4 <= x1) {
            cout << S;
            return 0;
        }
        else {
            xRight = min(x4, x2);
        }

        if (y2 <= y3) {
            cout << S;
            return 0;
        }
        else {
            yDown = max(y1, y3);
        }

        if (y4 <= y1) {
            cout << S;
            return 0;
        }
        else {
            yUp = min(y4, y2);
        }

        cout << S - ((xRight - xLeft) * (yUp - yDown));
    }

    return 0;
}