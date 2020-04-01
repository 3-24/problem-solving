#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b){
    if (a<b) swap(a,b);
    if (b == 0) return a;
    long long int r = a % b;
    return (gcd(b,r));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a,b;
    cin >> a >> b;
    int d = gcd(a,b);
    while (d--) cout << 1;
}