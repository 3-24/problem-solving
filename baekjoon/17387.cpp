#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;

uint8_t cross_product(lld dx1, lld dy1, lld dx2, lld dy2){
    lld prod = dx1 * dy2 - dx2 * dy1;
    return (prod > 0) - (prod < 0);
}

uint8_t ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    lld dx1 = x2 - x1;
    lld dy1 = y2 - y1;
    lld dx2 = x3 - x1;
    lld dy2 = y3 - y1;
    return cross_product(dx1, dy1, dx2, dy2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2, x3, y3, x4 ,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    bool success = 1;
    uint8_t ccw1 = ccw(x1, y1, x2, y2, x3 ,y3);
    uint8_t ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    if (ccw1 == ccw2 && ccw1 != 0){
        success = 0;
    } else {
        uint8_t ccw3 = ccw(x3, y3, x4, y4, x1, y1);
        uint8_t ccw4 = ccw(x3, y3, x4, y4, x2, y2);
        if (ccw3 == ccw4 && ccw3 != 0){
            success = 0;
        }
        // One line
        else if (ccw1 == ccw2 && ccw3 == ccw4 && ccw1 == ccw3 && ccw1 == 0){
            if (x1 > x2){
                swap(x1, x2);
                swap(y1, y2);
            } else if (x1 == x2 && y1 > y2) swap(y1, y2);
            if (x3 > x4){
                swap(x3, x4);
                swap(y3, y4);
            } else if (x3 == x4 && y3 > y4) swap (y3, y4);
            if (x2 < x3 || (x2 == x3 && y2 < y3)  ) success = 0;
            else if (x4 < x1 || (x4 == x1 && y4 < y1)) success = 0;
        }
    }
    cout << success;
    return 0;
}