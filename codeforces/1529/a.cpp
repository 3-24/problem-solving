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
        int min_a = 101;
        int a[n+1];
        ll count = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (a[i] < min_a){
                min_a = a[i];
                count = 1;
            }
            else if (a[i] == min_a){
                count++;
            }
        }
        cout << n - count << endl;
    }
    return 0;
}