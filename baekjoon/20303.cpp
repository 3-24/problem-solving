#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int candy[30001];
vector<vector<int>> graph;

bool visited[30001];
vector<int> weight;
vector<int> value;

void dfs(int vertex, int &w, int &val) {
    w += 1;
    val += candy[vertex];
    visited[vertex] = true;
    for (int u : graph[vertex]) {
        if (!visited[u]) dfs(u, w, val);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    graph = vector<vector<int>>(n, vector<int>());

    for (int i=0; i<n; i++){
        cin >> candy[i];
    }
    while (m--){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=0; i<n; i++){
        if (!visited[i]){
            int w = 0, v = 0;
            dfs(i, w, v);
            weight.push_back(w);
            value.push_back(v);
        }
    }

    int l = weight.size();
    
    // dp[i][j]: Maximum value with i-th candy and j weight
    vector<vector<int>> dp(l+1, vector<int>(k+1, 0));

    for (int i=1; i<=l; i++){
        int w = weight[i-1];
        int v = value[i-1];

        for (int j=1; j<=k; j++){
            if (j < w) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
        }
    }

    cout << dp[l][k-1];

    return 0;
}