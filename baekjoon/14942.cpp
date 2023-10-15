#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> energy(n, 0);
    for (int i=0; i<n; i++){
        cin >> energy[i];
    }

    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    for (int _=0; _<n-1; _++){
        int x, y, z;
        cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    vector<vector<pair<int, int>>> tree(n, vector<pair<int, int>>());
    vector<bool> visited(n, false);

    queue<int> Q;
    Q.push(0);
    visited[0] = true;

    while (!Q.empty()){
        int v = Q.front();
        Q.pop();

        for (auto [u, dist]: graph[v]){
            if (!visited[u]){
                tree[u].push_back({v, dist});
                for (int i=0; ; i++){
                    auto [ipar, idist] = tree[u][i];
                    if (tree[ipar].size() < i+1) break;
                    auto [iipar, iidist] = tree[ipar][i];
                    tree[u].push_back({iipar, iidist + idist});
                }
                visited[u] = true;
                Q.push(u);
            }
        }
    }

    for (int i=0; i<n; i++){
        int en = energy[i];
        int loc = i;
        while (true){
            if (loc == 0) break;
            if (tree[loc][0].second > en) break;
            int j;
            for (j=tree[loc].size()-1; j>=0; j--){
                if (tree[loc][j].second <= en) break;
            }
            en -= tree[loc][j].second;
            loc = tree[loc][j].first;
        }
        cout << loc + 1 << '\n';
    }
}