#include <bits/stdc++.h>

using namespace std;

const int MAX_PATH_LEN = INT_MAX >> 1;

vector<vector<int>> graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    graph = vector<vector<int>>(N, vector<int>(N, MAX_PATH_LEN));


    for (int i=0; i<N; i++){
        graph[i][i] = 0;
    }

    vector<tuple<int, int, int>> edges;

    for (int _=0; _<M; _++){
        int x, y, z;
        cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        edges.push_back({x, y, z});
        graph[x][y] = min(graph[x][y], z);
        graph[y][x] = min(graph[y][x], z);
    }

    // Floyd-Warshall
    for (int k=0; k<N; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int min_time = INT_MAX;
    for (int v=0; v<N; v++){
        int min_time_v = 0;
        for (auto [v1, v2, c]: edges){
            int cost_v1 = graph[v][v1];
            int cost_v2 = graph[v][v2];
            min_time_v = max(min_time_v, cost_v1 + cost_v2 + c);
        }

        min_time = min(min_time, min_time_v);
    }

    cout << fixed << setprecision(1) << float(min_time) / 2;
}