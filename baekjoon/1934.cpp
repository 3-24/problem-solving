#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a<b) swap(a,b);
    if (b == 0) return a;
    int r = a % b;
    return (gcd(b,r));

}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int a,b;
    while(t--){
        cin >> a >> b;
        cout << lcm(a,b) << endl;
    }
    return 0;
}