#include <bits/stdc++.h>

using namespace std;

int main(){
    double h,l;
    cin >> h >> l;
    double ans = (h*h + l*l) / (2*h) - h;
    cout << setprecision(14);
    cout << ans;
    return 0;
}
