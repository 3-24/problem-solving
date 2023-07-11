#include <bits/stdc++.h>

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n;
// dp[i][j] is cost to visit all nodes and return to 0.
int dp[16][1 << 17];    // -1: unexplored, >=0: visited and feasible, -2: infeasible
int adj[16][16];

int dfs(int i, int explored){
    if (dp[i][explored] == -1){
        int min_cost = INT_MAX;
        for (int j=0; j<n; j++){
            if (explored & (1 << j) || adj[i][j] == 0) continue;
            int cost = dfs(j, explored | (1 << j));
            if (cost == -2) continue;
            min_cost = min(cost+adj[i][j], min_cost);
        }
        if (min_cost == INT_MAX){
            dp[i][explored] = -2;
        } else{
            dp[i][explored] = min_cost;
        }
    }
    return dp[i][explored];
}

int main(){
    faster
    cin >> n;

    for (int i=0; i<n; i++){
        memset(dp[i], -1, sizeof(dp[i]));
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> adj[i][j];
        }
        if (i != 0){
            dp[i][(1 << n) -1] = -2;
        } else {
            dp[i][(1 << n) - 1] = 0;
        }
    }

    cout << dfs(0, 0);
    return 0;
}