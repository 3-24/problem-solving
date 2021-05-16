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
        ll A, B;
        cin >> A >> B;

        if ( B == 1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            ll x = (B+1) * A;
            ll y = A * B;
            ll z = x + y;
            cout << x << " "<< y << " " << z << endl;
        }
    }
    return 0;
}