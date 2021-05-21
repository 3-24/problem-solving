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
        ll i = 0;
        while (n != 0){
            n = n >> 1;
            i++;
        }
        cout << (1 << (i-1)) - 1 << endl;
    }
    return 0;
}