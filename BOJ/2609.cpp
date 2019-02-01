#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a<b) swap(a,b);
    if (b == 0) return a;
    int r = a % b;
    return (gcd(b,r));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    int d = gcd(a,b), m = a*b/d;
    cout << d << endl << m;
    return 0;
}