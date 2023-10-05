#include <bits/stdc++.h>

using namespace std;

#define MAX_VARS 10000

int vars, clauses;
vector<int> graph[MAX_VARS * 2];
int discovered[MAX_VARS * 2];
int scc[MAX_VARS * 2];
stack<int> st;
int visitCounter = 0;
int sccCounter = 0;

int dfs(int x) {
    int ret = discovered[x] = ++visitCounter;
    st.push(x);

    for (int y : graph[x]) {
        if (!discovered[y])
            ret = min(ret, dfs(y));
        else if (scc[y] == 0)
            ret = min(ret, discovered[y]);
    }

    if (ret == discovered[x]) {
        sccCounter += 1;
        while (true) {
            int t = st.top();
            st.pop();
            scc[t] = sccCounter;
            if (t == x) break;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> vars >> clauses;
    auto encoder = [](int x) {
        return (x > 0 ? (x - 1) * 2 : (-x - 1) * 2 + 1);
    };

    for (int i = 0; i < clauses; i++) {
        int x, y;
        cin >> x >> y;
        x = encoder(x);
        y = encoder(y);
        graph[x ^ 1].push_back(y);
        graph[y ^ 1].push_back(x);
    }

    for (int x = 0; x < 2 * vars; x++) {
        if (!discovered[x]) dfs(x);
    }

    bool satisfiable = true;
    for (int x = 0; x < vars; x++) {
        if (scc[x * 2] == scc[x * 2 + 1]) satisfiable = false;
    }

    if (!satisfiable)
        cout << 0;
    else {
        cout << 1 << '\n';
        for (int x = 0; x < vars; x++) {
            if (scc[x * 2] > scc[x * 2 + 1]) {
                cout << 0;
            } else {
                cout << 1;
            }
            cout << ' ';
        }
    }
}