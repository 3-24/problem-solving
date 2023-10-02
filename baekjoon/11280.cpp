#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> discovered;
vector<int> sccId;
int sccCounter = 0;
int vertexCounter = 0;

stack<int> st;

int scc(int u){
    int ret = discovered[u] = ++vertexCounter;
    st.push(u);
    // DFS on scc-free nodes
    for (int v: graph[u]){
        if (!discovered[v]) ret = min(ret, scc(v));
        else if (sccId[v] == -1) ret = min(ret, discovered[v]);
    }
    
    if (ret == discovered[u]){
        while (true){
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == u) break;
        }
        ++sccCounter;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> n >> m;
    graph = vector<vector<int>>(2 * n, vector<int>());
    discovered = vector<int>(2 * n, 0);
    sccId = vector<int>(2*n, -1);

    auto encode = [](int x) { return x > 0 ? (x - 1) * 2 : (-x - 1) * 2 + 1; };

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int ex = encode(x);
        int ey = encode(y);
        graph[ex ^ 1].push_back(ey);
        graph[ey ^ 1].push_back(ex);
    }

    // Tarjan's algorithm
    for (int i=0; i<2*n; i++){
        if (!discovered[i]) scc(i);
    }
    for (int i=0; i<n; i++){
        if (sccId[i << 1] == sccId[(i << 1) | 1]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}