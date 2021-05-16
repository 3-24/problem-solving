#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()

ll dp[6000][6000];

int main(){
    faster
    ll n;
    cin >> n;
    vector<int> ocp, emp;
    for (int i=1;i<=n;i++){
        int k;
        cin >> k;
        if (k == 0){
            emp.push_back(i);
        } else ocp.push_back(i);
    }

    for (ll i=0;i<=ocp.size();i++){
        for (ll j=0;j<=emp.size();j++){
            if (j < i) dp[i][j] = INT_MAX;      // more ocp than emp
            else if (i == 0) dp[i][j] = 0;      // empty ocp
            else {
                dp[i][j] = min(dp[i][j-1],
                                dp[i-1][j-1] + abs(emp[j-1] - ocp[i-1]));
            }
        }
    }
    cout << dp[ocp.size()][emp.size()] << endl;
    return 0;
}