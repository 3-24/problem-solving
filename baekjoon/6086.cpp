#include <bits/stdc++.h>

#define fasterio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
const int MAX_NODES=52;

int cap[MAX_NODES][MAX_NODES], flow[MAX_NODES][MAX_NODES];
vector<int> adj[MAX_NODES];

int ford(int src, int sink){
    int res = 0;

    while (true){
        vector<int> visited(MAX_NODES, -1);
        queue<int> q;
        q.push(src);

        while (!q.empty()){
            int start = q.front();
            q.pop();

            for (int end: adj[start]){
                if (cap[start][end] > flow[start][end] && visited[end] == -1){
                    q.push(end);
                    visited[end] = start;
                    if (end == sink) break;
                }
            }
        }

        if (visited[sink] == -1) break;

        int f = INT_MAX;
        for (int i=sink; i!=src; i = visited[i]){
            int i_prev = visited[i];
            f = min(f, cap[i_prev][i] - flow[i_prev][i]);
        }

        for (int i=sink; i!=src; i = visited[i]){
            int i_prev = visited[i];
            flow[i_prev][i] += f;
            flow[i][i_prev] -= f;
        }

        res += f;
    }

    return res;
}

int main(){
    fasterio();
    auto encode = [&](char c){
        if ('A' <= c && c <= 'Z'){
            return c - 'A';
        } else {
            return 26 + (c - 'a');
        }
    };
    
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        char x, y;
        int cap_t;
        cin >> x >> y >> cap_t;
        int x_t = encode(x);
        int y_t = encode(y);
        cap[x_t][y_t] += cap_t;
        cap[y_t][x_t] += cap_t;
        adj[x_t].push_back(y_t);
        adj[y_t].push_back(x_t);
    }

    cout << ford(encode('A'), encode('Z')) << '\n';
    return 0;
}