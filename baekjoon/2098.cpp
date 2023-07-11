#include <bits/stdc++.h>

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int adj[16][16];
int visited[16];
int min_cost = INT_MAX;

void dfs(int i, int explored, int cost){
    if (cost >= min_cost) return;
    
    if (explored == n){
        if (adj[i][0] != 0) min_cost = min(min_cost, cost + adj[i][0]);
        return;
    }

    for (int next=0; next<n; next++){
        if (adj[i][next] == 0 || visited[next]) continue;
        visited[next] = true;
        dfs(next, explored+1, cost + adj[i][next]);
        visited[next] = false;
    }
    return;
}

int main(){
    faster
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> adj[i][j];
        }
    }
    visited[0] = true;
    dfs(0, 1, 0);
    cout << min_cost;
    return 0;
}