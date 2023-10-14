#include <bits/stdc++.h>

using namespace std;

string S;
int count = 0;
const int mod = 10007;
int l;

vector<vector<int>> dp;
vector<vector<bool>> updated;

int dp_unit(int s, int e){
    if (!updated[s][e]){
        if (e - s == 0){
            dp[s][e] = 0;
        } else if (e-s == 1){
            dp[s][e] = 1;
        } else {
            int res;
            if (S[s] == S[e-1]){
                res = dp_unit(s+1, e) + dp_unit(s, e-1) + 1;
            } else {
                res = dp_unit(s+1, e) + dp_unit(s, e-1) - dp_unit(s+1, e-1);
            }
            dp[s][e] = (res+mod) % mod;
        }
        updated[s][e] = true;
    }
    return dp[s][e];
}

int main(){
    cin >> S;
    l = S.length();

    dp = vector<vector<int>>(l, vector<int>(l+1, 0));
    updated = vector<vector<bool>>(l, vector<bool>(l+1, false));

    cout << dp_unit(0, l);
}