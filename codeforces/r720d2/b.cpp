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
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }

        ll x, y;
        ll count = 0;
        for (int i=1;i<n;i++){
            x = arr[i-1];
            y = arr[i];
            if (__gcd(x,y) == 1) continue;
            
            result[count][0] = i-1;
            result[count][1] = i;
            if (x <= y){
                result[count][2] = x;
                result[count][3] = x+1;
                arr[i] = x+1;
            } 
            else {
                if (i == 1){
                    result[count][2] = y+1;
                    arr[i-1] = y+1;
                }
                else{
                    result[count][2] = y*arr[i-2] + 1;
                    arr[i-1] = y*arr[i-2] + 1;
                }
                result[count][3] = y;
            }
            count++;
        }
        cout << count << endl;
        for (int i=0; i<count; i++){
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << endl;
        }
    }
    return 0;
}