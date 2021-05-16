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
        ll n;
        cin >> n;
        ll univ_arr[n+3];
        ll score_arr[n+3];
        vector<ll> univ[n+3];
        vector<ll> pre[n+3];        // array of prefix sum

        for (ll i=0;i<n;i++) cin >> univ_arr[i];
        for (ll i=0;i<n;i++) cin >> score_arr[i];
        for (ll i=0;i<n;i++) univ[univ_arr[i]].push_back (score_arr[i]);
        
        for (ll i=1;i<=n;i++){
            if (univ[i].empty()) continue;
            sort(all(univ[i]));
            pre[i].push_back(univ[i][0]);
            for (ll j=1; j<univ[i].size(); j++){
                pre[i].push_back(pre[i][j-1] + univ[i][j]);
            }
        }

        ll ans[n+3];
        memset(ans, 0, sizeof(ans));
        for (ll i=1; i<=n; i++){
            for (ll k=1; k<=univ[i].size();k++){
                ans[k] += pre[i].back();
                ll r = univ[i].size() % k;
                if (r > 0) ans[k] -= pre[i][r-1];
            }
        }

        for (ll i=1; i<=n; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}