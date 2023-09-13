#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX_N 15
#define MAX_MOD 100

int MOD, N;
ll dp[1 << MAX_N][MAX_MOD];
vector<int> nums;
vector<int> digits;
vector<int> pow10_mod_mem;

int pow10_mod(int x){
    if (pow10_mod_mem.size() == 0) pow10_mod_mem.push_back(1 % MOD);
    while ((int)pow10_mod_mem.size() < x+1){
        pow10_mod_mem.push_back((pow10_mod_mem.back() * 10) % MOD);
    }
    return pow10_mod_mem[x];
}

ll step(int state, int r){
    assert(state < (1 << N) && r < MOD);
    if (dp[state][r] == -1){
        dp[state][r] = 0;
        int digits_sum = 0;
        for (int i=0; i<N; i++){
            if (((state >> i) & 1) == 0) digits_sum += digits[i];
        }
        for (int i=0; i<N; i++){
            if ((state >> i) & 1){
                int new_r = (r + pow10_mod(digits_sum) * nums[i] ) % MOD;
                dp[state][r] += step(state - (1 << i), new_r);
            }
        }
    }
    return dp[state][r];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<string> nums_str;
    for (int i=0; i<N; i++){
        string s;
        cin >> s;
        digits.push_back(s.length());
        nums_str.push_back(s);
    }
    cin >> MOD;

    for (int i=0; i<N; i++){
        int mod = 0;
        string &s = nums_str[i];
        for (int digit=0; digit<s.length(); digit++){
            int x = s[s.length() - digit - 1] - '0'; 
            mod += (x * pow10_mod(digit));
            mod %= MOD;
        }
        nums.push_back(mod);
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 1;
    for (int i=1; i<MOD; i++){
        dp[0][i] = 0;
    }

    ll count_seqs = step((1 << N) - 1, 0);
    
    if (count_seqs == 0){
        cout << "0/1\n";
    } else {
        ll denom = 1;
        for (int i=1; i<=N; i++){
            denom *= i;
        }
        ll d = gcd(denom, count_seqs);
        cout << count_seqs / d << '/' << denom / d << '\n';
    }

    return 0;
}