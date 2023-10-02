#include <bits/stdc++.h>

using namespace std;

int v;
vector<vector<int>> graph;
vector<pair<int, int>> cut_edge;
vector<int> discovered;
vector<int> parent;
int counter = 0;

pair<int, int> edge(int u, int v){
    if (u < v) return {u, v};
    else return {v, u};
}

int dfs(int u){
    int ret = discovered[u] = ++counter;
    for (int v: graph[u]){
        if (!discovered[v]){
            parent[v] = u;
            int ret2 = dfs(v);
            if (ret2 > discovered[u]) cut_edge.push_back(edge(u, v));
            ret = min(ret, ret2);
        } else {
            if (v == parent[u]) continue;
            ret = min(discovered[v], ret);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int e;
    cin >> v >> e;
    graph = vector<vector<int>>(v, vector<int>());
    discovered = vector<int>(v, 0);
    parent = vector<int>(v, -1);

    for (int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=0; i<v; i++){
        if (!discovered[i]) dfs(i);
    }

    sort(cut_edge.begin(), cut_edge.end());
    cout << cut_edge.size() << '\n';
    for (auto [u, v]: cut_edge){
        cout << u+1 << ' ' << v+1 << '\n';
    }
}