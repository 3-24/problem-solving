#include <bits/stdc++.h>

using namespace std;

int N;
int row[501];
int col[501];
int dp[501][501];

int step(int s, int e){
    if (e == s + 1) return 0;
    if(dp[s][e] == 0){
        int min_mult = INT_MAX;
        for (int m=s+1; m<e; m++){
            min_mult = min(min_mult, step(s, m) +  step(m, e) + row[s] * row[m] * col[e-1] );
        }
        dp[s][e] = min_mult;
    }
    return dp[s][e];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> row[i] >> col[i];
    }

    cout << step(0, N);
}