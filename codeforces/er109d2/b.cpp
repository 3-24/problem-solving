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
        ll l;
        cin >> l;
        ll arr[l+3];
        for (ll i=1;i<=l;i++){
            cin >> arr[i];
        }
        if (arr[1] == 1 && arr[l] == l){
            bool is_sorted = true;
            for (ll i=2;i<l;i++){
                if (arr[i] != i){
                    is_sorted = false;
                    break;
                }
            }
            if (is_sorted) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if (arr[1] == 1 || arr[l] == l){
            cout << 1 << endl;
        }
        else if (arr[1] == l && arr[l] == 1){
            cout << 3 << endl;
        }
        else cout << 2 << endl;
    }
    return 0;
}