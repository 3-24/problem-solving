#include <bits/stdc++.h>

using namespace std;

// Critical Path
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    vector<vector<array<int, 3>>> inv_graph(n, vector<array<int, 3>>());
    vector<int> in_degree(n, 0);
    vector<int> max_w(n, 0);
    int start, end;

    for (int i=0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x -= 1;
        y -= 1;
        graph[x].push_back({y, w});
        inv_graph[y].push_back({x, w, i});
        in_degree[y] += 1;
    }
    
    cin >> start >> end;
    start -= 1;
    end -= 1;
    
    queue<int> Q;
    Q.push(start);

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (auto [v, w]: graph[u]){
            max_w[v] = max(max_w[v], w + max_w[u]);
            in_degree[v] -= 1;
            if (in_degree[v] == 0) Q.push(v);
        }
    }

    set<int> edges;
    vector<bool> visited(n, false);
    Q.push(end);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w, i]: inv_graph[u]){
            if (max_w[u] == max_w[v] + w){
                edges.insert(i);
                Q.push(v);
            }
        }
    }

    cout << max_w[end] << '\n' << edges.size() << '\n';
    return 0;
}