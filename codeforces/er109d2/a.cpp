#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

int main(){
    faster
    ll t;
    cin >> t;
    while (t--){
        ll k;
        cin >> k;
        ll d = __gcd(100-k, k);
        cout << (100-k) / d + k / d << endl;
    }
    return 0;
}