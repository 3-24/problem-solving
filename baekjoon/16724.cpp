#include <bits/stdc++.h>

using namespace std;

int n, m;
int encode(int x, int y){
    return m*x + y;
}

bool visited[1000*1000];
int graph[1000*1000];
int ds[1000*1000];

int ds_root(int v){
    int u = v;
    while (ds[u] != u){
        u = ds[u];
    }
    return u;
}

void dfs(set<int> dfs_nodes, int v){
    dfs_nodes.insert(v);
    visited[v] = true;
    int u = graph[v];
    if (!visited[u]){
        ds[v] = u;
        dfs(dfs_nodes, u);
    } else {
        if (!dfs_nodes.contains(u)){
            ds[v] = u;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i=0; i<n*m; i++){
        ds[i] = i;
    }

    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            char c = s[j];
            int v1 = encode(i, j);
            int v2;
            if (c == 'L') v2 = encode(i, j-1);
            else if (c == 'R') v2 = encode(i, j+1);
            else if (c == 'U') v2 = encode(i-1, j);
            else v2 = encode(i+1, j);
            graph[v1] = v2;
        }
    }

    for (int v=0; v<m*n; v++){
        if (!visited[v]){
            dfs(set<int>(), v);
        }
    }

    int count = 0;
    for (int i=0; i<m*n; i++){
        if (ds[i] == i) count++;
    }

    cout << count;

    return 0;
}