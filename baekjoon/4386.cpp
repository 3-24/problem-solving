#include <bits/stdc++.h>

using namespace std;

int n;
float coord[100][2];
float edge[100][100];
bool visited[100];
// MIN Heap
priority_queue<tuple<float, int, int>> heap;
float total_cost;

float geo_dist(int i, int j){
    float x = coord[i][0] - coord[j][0];
    float y = coord[i][1] - coord[j][1];
    return sqrt(x*x + y*y);
}

void prim(int node){
    visited[node] = true;

    for (int v=0; v<n; v++){
        if (visited[v]) continue;
        heap.push(tuple<float, int, int>(-edge[node][v], node, v));
    }

    while (!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int v = get<2>(t);
        if (visited[v]) continue;
        visited[v] = true;
        total_cost += -get<0>(t);

        for (int i=0; i<n; i++){
            if (!visited[i]){
                heap.push(tuple<float, int, int>(-edge[v][i], v, i));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> coord[i][0] >> coord[i][1];
        // ds[i] = i;
    }

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            float d = geo_dist(i, j);
            edge[i][j] = d;
            edge[j][i] = d;
        }
    }

    prim(0);
    cout <<fixed << setprecision(2) << total_cost;
    
    return 0;
}