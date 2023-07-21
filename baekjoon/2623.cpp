#include <bits/stdc++.h>

using namespace std;

int N, M;

set<int> to_nodes[1001];
int in_degree[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    while (M--){
        int l;
        cin >> l;
        if (l == 1) continue;
        int a, b;
        cin >> a;
        for (int i = 1; i < l; i++){
            cin >> b;
            to_nodes[a].insert(b);
            a = b;
        }
    }

    for (int i=1; i<=N; i++){
        for (auto j: to_nodes[i]){
            in_degree[j] += 1;
        }
    }

    stack<int> s;

    for (int i=1; i<= N; i++){
        if (in_degree[i] == 0) s.push(i);
    }

    vector<int> sol;
    while (!s.empty()){
        int x = s.top();
        s.pop();
        sol.push_back(x);
        for (auto y: to_nodes[x]){
            in_degree[y] -= 1;
            if (in_degree[y] == 0){
                s.push(y);
            } 
        }
    }

    if (sol.size() != N) cout << 0;
    else {
        for (auto x: sol){
            cout << x << '\n';
        }
    }

    return 0;
}