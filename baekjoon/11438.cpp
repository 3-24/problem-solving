#include <bits/stdc++.h>

using namespace std;


int log2(int n){
    assert(n>0);
    int count = 0;
    while (n != 0){
        n >>= 1;
        count += 1;
    }
    return count-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>());
    for (int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<vector<int>> parent(N, vector<int>());
    vector<int> depth(N, 0);
    
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int n = q.front();
        q.pop();
        for (int m: adj[n]){
            if (depth[m] == 0 && m != 0){
                parent[m].push_back(n);
                int d = depth[n] + 1;
                depth[m] = d;
                int i = 0;
                while (1 << (i+1) <= d){
                    parent[m].push_back(parent[parent[m][i]][i]);
                    i += 1;
                }
                q.push(m);
            }
        }
    }

    int m;
    cin >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        
        if (depth[x] < depth[y]) swap(x, y);

        if (y == 0){
            cout << 1 << '\n';
            continue;
        }

        while (depth[x] > depth[y]){
            int diff = depth[x] - depth[y];
            x = parent[x][log2(diff)];
        }

        assert(depth[x] == depth[y]);

        if (x == y){
            cout << x+1 << '\n';
            continue;
        }

        while (parent[x][0] != parent[y][0]){
            for (int i=parent[x].size()-1; i>=0; i--){
                if (parent[x][i] != parent[y][i]){
                    x = parent[x][i];
                    y = parent[y][i];
                    break;
                }
            }
        }

        cout << parent[x][0] + 1 << '\n';
    }
}