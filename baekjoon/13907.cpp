#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K, S, D;
    cin >> N >> M >> K;
    cin >> S >> D;
    S -= 1;
    D -= 1;
    vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
    for (int i=0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a -= 1;
        b -= 1;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    priority_queue<array<int, 3>> pq;
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX >> 1));

    pq.push({0, 0, S}); // -cost, -length, node
    dist[S][0] = 0;

    while (!pq.empty()){
        auto [c, l, v] = pq.top();
        pq.pop();
        if (dist[v][-l] < -c) continue;
        for (auto [u, w]: graph[v]){
            int new_c = c - w;
            int new_l = l - 1;
            if (-new_l >= N) continue;
            if (dist[u][-new_l] > -new_c){
                dist[u][-new_l] = -new_c;
                pq.push({new_c, new_l, u});
            }
        }
    }

    auto get_min = [&dist, &N, &D](){
        int min_val = INT_MAX;
        for (int i=0; i<N; i++){
            min_val = min(min_val, dist[D][i]);
        }
        return min_val;
    };

    cout << get_min() << '\n';

    for (int i=0; i<K; i++){
        int tax;
        cin >> tax;
        for (int l=0; l<N; l++){
            dist[D][l] += l * tax;
        }
        cout << get_min() << '\n';
    }
}