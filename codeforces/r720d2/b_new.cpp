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
        ll arr[n];
        ll result[n][4];
        ll min_elem = LLONG_MAX;
        ll min_idx;
        for (int i=0;i<n;i++){
            cin >> arr[i];
            if (min_elem > arr[i]){
                min_idx = i;
                min_elem = arr[i];
            }
        }
        ll count = 0;
        for (int i=0; i<n; i++){
            if (min_idx == i) continue;

            if ((min_idx - i) % 2 == 0){
                if (arr[i] == min_elem) continue;
                result[count][0] = i;
                result[count][1] = min_idx;
                result[count][2] = min_elem;
                result[count][3] = min_elem;
            }
            else {
                if (arr[i] == min_elem + 1) continue;
                result[count][0] = i;
                result[count][1] = min_idx;
                result[count][2] = min_elem+1;
                result[count][3] = min_elem;
            }
            count++;
        }

        cout << count << endl;
        for (ll i=0; i<count;i++){
            cout << result[i][0]+1 << " " << result[i][1]+1 << " " << result[i][2] << " " << result[i][3] << endl;
        }
    }
    return 0;
}