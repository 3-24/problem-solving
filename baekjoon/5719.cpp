#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};

void solve(int n, int m){
    int s, d;
    cin >> s >> d;
    vector<vector<int>> weight(n, vector<int>(n, 0));
    vector<set<int>> adj(n, set<int>());
    for (int _=0; _<m; _++){
        int x, y, w;
        cin >> x >> y >> w;
        weight[x][y] = w;
        adj[x].insert(y);
    }

    vector<int> dists(n, INT_MAX);
    vector<vector<int>> prev_nodes(n, vector<int>());
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({0, s});
    dists[s] = 0;
    while (!pq.empty()){
        auto [dist, u] = pq.top();
        pq.pop();
        for (int v: adj[u]){
            int new_dist = dist + weight[u][v];
            if (new_dist < dists[v]){
                dists[v] = new_dist;
                prev_nodes[v].clear();
                prev_nodes[v].push_back(u);
                pq.push({new_dist, v});
            } else if (new_dist == dists[v]){
                prev_nodes[v].push_back(u);
            }
        }
    }

    set<int> visited;
    queue<int> q;
    q.push(d);
    visited.insert(d);
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (auto y: prev_nodes[x]){
            adj[y].erase(x);
            if (!visited.contains(y)){
                visited.insert(y);
                q.push(y);
            }
        }
    }

    dists = vector<int>(n, INT_MAX);
    pq.push({0, s});
    dists[s] = 0;
    while (!pq.empty()){
        auto [dist, u] = pq.top();
        pq.pop();
        for (int v: adj[u]){
            int new_dist = dist + weight[u][v];
            if (new_dist < dists[v]){
                dists[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    cout << (dists[d] == INT_MAX ? -1 : dists[d]) << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true){
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve(n, m);
    }
}