#include <bits/stdc++.h>

using namespace std;

#define MOD 10007

int N;

int comb_mod[53][53];

int comb(int n, int r){
    if (comb_mod[n][r] == 0){
        if (r == 0 || r == n) comb_mod[n][r] = 1;
        else comb_mod[n][r] = (comb(n-1, r-1) + comb(n-1, r)) % MOD;
    }
    return comb_mod[n][r];
}

int main(){
    cin >> N;
    int count = 0;
    for (int i=1; 4*i<=N; i++){
        int cases = (comb(13, i) * comb(52 - 4*i, N - 4*i)) % MOD;
        if (i % 2 == 1) count += cases;
        else count -= cases;

        count = (count % MOD + MOD) % MOD;
    }
    cout << count;
}