#include <bits/stdc++.h>

using namespace std;

int log2(int n){
    assert(n > 0);
    int count = -1;
    while (n != 0){
        n = n >> 1;
        count += 1;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;
    vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>{});
    for (int i = 0; i < N - 1; i++)
    {
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        --v1;
        --v2;
        graph[v1].push_back({v2, d});
        graph[v2].push_back({v1, d});
    }

    vector<vector<int>> parent(N, vector<int>{});
    vector<int> depth(N, 0);
    vector<int> cost(N, 0);
    vector<bool> visited(N, false);

    queue<int> Q;
    Q.push(0);
    visited[0] = true;

    while (!Q.empty())
    {
        int par = Q.front();
        Q.pop();
        for (auto [child, dist] : graph[par])
        {
            if (visited[child]) continue;
            visited[child] = true;
            // Update depth
            depth[child] = depth[par] + 1;
            // Update cost
            cost[child] = cost[par] + dist;
            // Update parent
            parent[child].push_back(par);
            for (int i = 1; (1 << i) <= depth[child]; i++)
            {
                parent[child].push_back(parent[parent[child][i - 1]][i - 1]);
            }

            Q.push(child);
        }
    }

    cin >> M;
    while (M--)
    {
        int x, y, ans = 0;
        cin >> x >> y;
        --x;
        --y;

        ans += cost[x] + cost[y];

        if (depth[x] < depth[y])
            swap(x, y);

        while (depth[x] > depth[y])
        {
            int depth_diff = depth[x] - depth[y];
            x = parent[x][log2(depth_diff)];
        }
        assert(depth[x] == depth[y]);

        int ancestor;
        if (x == y){
            ancestor = x;
        } else {
            while (parent[x][0] != parent[y][0]){
                for (int i=parent[x].size()-1; i>=0; i--){
                    if (parent[x][i] != parent[y][i]){
                        x = parent[x][i];
                        y = parent[y][i];
                        break;
                    }
                }
            }
            ancestor = parent[x][0];
        }
        ans -= 2 * cost[ancestor];
        cout << ans << '\n';
    }
}