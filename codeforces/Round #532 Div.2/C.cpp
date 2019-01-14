#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10);
    int n,r;
    cin >> n >> r;

    ld calc = sin(PI/ld(n));
    cout << (ld(r)*calc) / (1-calc);
    return 0;
}