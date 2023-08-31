#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000

array<vector<int>, MAX_N> edges_;
array<vector<int>, MAX_N> edges;

int N;
int dp[MAX_N][2];               // 0: White, 1: Black

int step(int node, bool color){
    if (dp[node][color] == -1){
        if (color == 1){
            int acc = 1;
            for (int node_next: edges[node]){
                acc += min(step(node_next, 0), step(node_next, 1));
            }
            dp[node][color] = acc;
        } else {
            int acc = 0;
            for (int node_next: edges[node]){
                acc += step(node_next, 1);
            }
            dp[node][color] = acc;
        }
    }

    return dp[node][color];
}

bool visited[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0; i<N; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    for (int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        edges_[u].push_back(v);
        edges_[v].push_back(u);
    }

    // Prepare directed graph for dynamic programming!
    queue<int> bfs_queue;
    bfs_queue.push(0);

    while (!bfs_queue.empty()){
        int node = bfs_queue.front();
        bfs_queue.pop();
        visited[node] = true;
        for (int next_node: edges_[node]){
            if (visited[next_node]) continue;
            edges[node].push_back(next_node);
            bfs_queue.push(next_node);
        }
    }


    cout << min(step(0, 0), step(0, 1));
}