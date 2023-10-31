#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> discovered;
vector<int> scc;
int n, m;
int vertexCounter, sccCounter;

stack<int> st;

int do_scc(int u){
    int ret = discovered[u] = ++vertexCounter;
    st.push(u);

    for (int v: graph[u]){
        if (!discovered[v]) ret = min(ret, do_scc(v));
        else if (scc[v] == -1) ret = min(ret, discovered[v]);
    }

    if (ret == discovered[u]){
        while (true){
            int t = st.top();
            st.pop();
            scc[t] = sccCounter;
            if (t == u) break;
        }
        ++sccCounter;
    }

    return ret;
}

int main(){
    auto encode = [](int x){
        return x > 0 ? 2*(x-1) : 2*(-x-1) + 1;
    };
    while (cin >> n >> m){
        graph = vector<vector<int>>(n*2, vector<int>());
        discovered = vector<int>(n*2, 0);
        scc = vector<int>(n*2, -1);
        st = stack<int>();
        vertexCounter = 0;
        sccCounter = 0;

        for (int i=0; i<m; i++){
            int x, y;
            cin >> x >> y;
            x = encode(x);
            y = encode(y);
            graph[x ^ 1].push_back(y);
            graph[y ^ 1].push_back(x);
        }

        for (int i=0; i<2*n; i++){
            if (!discovered[i]) do_scc(i);
        }

        bool success = true;
        for (int i=0; i<2*n; i+=2){
            if (scc[i] == scc[i+1]){
                success = false;
                break;
            }
        }
        
        if (success){
            stack<int> dfs_st;
            vector<bool> visited(2*n, false);
            dfs_st.push(0);
            visited[0] = true;
            while (!dfs_st.empty()){
                int t = dfs_st.top();
                dfs_st.pop();
                for (int next: graph[t]){
                    if (!visited[next]){
                        if (next == 1){
                            success = false;
                            break;
                        }
                        visited[next] = true;
                        dfs_st.push(next);
                    }
                }
            }
        }

        if (success) cout << "yes\n";
        else cout << "no\n";
    }
}