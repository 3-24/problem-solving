#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

int main(){
    ll t;
    int arr[1002];
    ll dp[1001];    // ALICE - BOB
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int m=3;m<=1000;m++){
        if (m % 2 == 0){
            dp[m] =  2 + dp[m-2];
        }
        else {
            dp[m] = min(2 + dp[m-2], 1 - dp[m-1]);
        }
    }
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ll count_zero = 0;
        char fullinput[n+3];
        scanf("%s", fullinput);
        for (ll i=0;i<n;i++){
            if (fullinput[i] == '0') count_zero++;
        }

        if (dp[count_zero] == 0) cout << "DRAW\n";
        else if (dp[count_zero] > 0) cout << "BOB\n";
        else cout << "ALICE\n";
    }
    return 0;
}