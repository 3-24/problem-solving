#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define RATE_CHANGED(x,y,m) ((y+m)*100/(x+m) > (y*100)/x)

int main(){
    ll x,y;
    cin >> x >> y;
    ll left = 0, right = 1000000000;
    ll m;
    if (!RATE_CHANGED(x,y,right)){
        cout << -1;
        return 0;
    }
    while (1){
        m = (left + right) / 2;
        if (m == left) break;
        if (RATE_CHANGED(x,y,m)) right = m;
        else left = m;
    }
    cout << m+1;
    return 0;
}