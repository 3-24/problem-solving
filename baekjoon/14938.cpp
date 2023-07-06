#include <bits/stdc++.h>
using namespace std;

// # of locations, search range, # of edges
// 1 <= n <= 100
// 1 <= m <= 15
// 1 <= r <= 100
int n, m, r;
int items[101];
int dist[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for (int i=0; i<n; i++){
        cin>> items[i];
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j){
                dist[i][j] = 0;
            } else {
                dist[i][j] = INT_MAX >> 1;
            }
        }
    }

    while(r--){
        int x, y, v;
        cin >> x >> y >> v;
        dist[x-1][y-1] = v;
        dist[y-1][x-1] = v;
    }
    
    // Floyd-Warshall
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int max_score = 0;

    for (int i=0; i<n; i++){
        int score = 0;
        for (int j=0; j<n; j++){
            if (dist[i][j] <= m){
                score += items[j];
            }
        }
        max_score = max(score, max_score);
    }

    cout << max_score;

    return 0;
}