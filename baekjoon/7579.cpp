#include <bits/stdc++.h>

using namespace std;

int N, M;
int mem[128];
int cost[128];

int dp[128][10001];

int step(int i, int c){
    if (c < 0) return INT_MIN;
    if (i == N) return 0;
    if (dp[i][c] == 0) {
        dp[i][c] = max(step(i+1, c), mem[i] + step(i+1, c - cost[i]));
    }
    return dp[i][c];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> mem[i];
    }
    int max_cost = 0;
    for (int i=0; i<N; i++){
        cin >> cost[i];
        max_cost += cost[i];
    }

    for (int c=0; c<=max_cost; c++){
        if (step(0,c) >= M){
            cout << c;
            break;
        }
    }
    return 0;
}