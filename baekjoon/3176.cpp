#include <bits/stdc++.h>

using namespace std;

int log2(int n){
    assert(n > 0);
    int count = 0;
    while (n != 0){
        n >>= 1;
        count += 1;
    }
    return count - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> graph(N, vector<pair<int,int>>());
    for (int i=0; i<N-1; i++){
        int A, B, C;
        cin >> A >> B >> C;
        A -= 1;
        B -= 1;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    vector<vector<array<int, 3>>> parent(N, vector<array<int, 3>>());
    
    vector<bool> visited(N, false);
    vector<int> depth(N, 0);
    queue<int> bfs;
    visited[0] = true;
    bfs.push(0);

    while (!bfs.empty()){
        int x = bfs.front();
        bfs.pop();
        for (auto [y, w]: graph[x]){
            if (visited[y]) continue;
            visited[y] = true;
            depth[y] = depth[x] + 1;
            parent[y].push_back({x, w, w});
            for (int i=1; i <= log2(depth[y]); i++){
                auto [par1, min_w1, max_w1] = parent[y][i-1];
                auto [par2, min_w2, max_w2] = parent[par1][i-1];
                parent[y].push_back({
                    par2, 
                    min(min_w1, min_w2), 
                    max(max_w1, max_w2)
                });
            }
            bfs.push(y);
        }
    }

    int K;
    cin >> K;
    for (int i_ = 0; i_ < K; i_++){
        int D, E;
        cin >> D >> E;
        D -= 1;
        E -= 1;

        if (depth[D] < depth[E]) swap(D, E);

        int min_w = INT_MAX;
        int max_w = INT_MIN;
        while(depth[D] != depth[E]){
            int diff = depth[D] - depth[E];
            auto res = parent[D][log2(diff)];
            D = res[0];
            min_w = min(min_w, res[1]);
            max_w = max(max_w, res[2]);
        }
        
        assert(depth[D] == depth[E]);

        if (D == E){
            cout << min_w << ' ' << max_w << '\n';
            continue;
        }

        while (parent[D][0][0] != parent[E][0][0]){
            int i;
            for (i=parent[D].size() - 1; i >= 0; i--){
                if (parent[D][i][0] != parent[E][i][0]) break;
            }
            auto [new_D, min_w1, max_w1] = parent[D][i];
            auto [new_E, min_w2, max_w2] = parent[E][i];
            D = new_D;
            E = new_E;
            min_w = min({min_w, min_w1, min_w2});
            max_w = max({max_w, max_w1, max_w2});
        }
        
        min_w = min({min_w, parent[D][0][1], parent[E][0][1]});
        max_w = max({max_w, parent[D][0][2], parent[E][0][2]});
        cout << min_w << ' ' << max_w << '\n';
    }
}