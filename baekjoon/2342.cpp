#include <bits/stdc++.h>

using namespace std;

int cost[5][5] = {
    {1, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
};

// Goal: find dp[n][0 || 0]
// Base: dp[0][x] is always 0.
// 1 2 2 4 0
// dp[5][(0, 0)] = dp[4][(1,0)] + 2
// dp[4][(1,0)] = min(dp[3][(1,2)] + 2, dp[3][(2,0)] + 3)
map<vector<int>, int> dp;
vector<int> prob;

int step(int x, int a, int b){
    if (x == 0) return 0;
    if (a > b) swap(a,b);

    vector<int> v = vector<int>{x, a, b};

    if (!dp.contains(v)){
        // x -> x-1;
        int new_pos = prob[prob.size() - x];
        dp[v] = min(step(x-1, new_pos, b) + cost[a][new_pos], step(x-1, a, new_pos) + cost[b][new_pos]);
    }
    return dp[v];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    while (true){
        int i;
        cin >> i;
        if (i == 0) break;
        prob.push_back(i);
    }

    cout << step(prob.size(), 0, 0);

    return 0;
}