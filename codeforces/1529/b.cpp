#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

int main(){
    //faster
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a;


        for (int i=0;i<n;i++){
            ll v;
            cin >> v;
            a.push_back(v);
        }

        if (n == 1){
            cout << "1\n";
            continue;
        }
        sort(all(a));


        ll min_diff = INT_MAX;
        int i;
        for (i=1;i<n;i++){
            if (a[i] > 0){
                if (i == 1){
                    if (a[i-1] > 0){
                        i = 0;
                    }
                }
                break;
            }
            if (min_diff > a[i] - a[i-1]){
                min_diff = a[i] - a[i-1];
            }
        }
        if (a[i] <= min_diff && a.back() > 0) cout << i+1 << endl;
        else cout << i << endl;
    }
    return 0;
}