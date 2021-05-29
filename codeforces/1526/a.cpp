#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

int main(){
    faster
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[2*n];
        for (ll i=0;i<2*n;i++){
            cin >> a[i];
        }
        sort(a, a+2*n);
        for (ll i=0;i<2*n;i++){
            if (i % 2  == 0){
                cout << a[i/2] << " ";
            }
            else {
                cout << a[2*n- i/2 - 1] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}