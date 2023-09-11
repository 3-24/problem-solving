#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> bfs;

int world[1000][1000];
int dist[1000][1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> world[i][j];
            if (world[i][j] == 2){
                dist[i][j] = 0;
                bfs.push({i, j});
            } else {
                dist[i][j] = -world[i][j];
            }
        }
    }

    while (!bfs.empty()){
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int i=0; i<4; i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && dist[x1][y1] == -1 && world[x1][y1] != 0){
                dist[x1][y1] = dist[x][y] + 1;
                bfs.push({x1, y1});
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}