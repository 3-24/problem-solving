#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int N;
int visited[MAX_N];
int total_cost;
priority_queue<tuple<int, int>> heap;  // MIN HEAP

void add_edge(vector<pair<int, int>> &arr, vector<map<int, int>> &edges){
    sort(arr.begin(), arr.end());
    for (int i=0; i<N-1; i++){
        int j = i+1;
        auto [loc_i, vi] = arr[i];
        auto [loc_j, vj] = arr[j];
        int w = loc_j - loc_i;
        if (edges[vi].contains(vj) && edges[vi][vj] < w) continue;
        edges[vi][vj] = w;
        edges[vj][vi] = w;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<map<int, int>> edges(N, map<int, int>());

    vector<pair<int, int>> arrX, arrY, arrZ;

    for (int i=0; i<N; i++){
        int x, y, z;
        cin >> x >> y >> z;
        arrX.push_back({x, i});
        arrY.push_back({y, i});
        arrZ.push_back({z, i});
        visited[i] = INT_MIN + 1;
    }

    add_edge(arrX, edges);
    add_edge(arrY, edges);
    add_edge(arrZ, edges);

    // Prim's algorithm
    heap.push({0, 0});

    while (!heap.empty()){
        auto [w, i] = heap.top();
        heap.pop();
        if (visited[i] > 0) continue;
        visited[i] = true;
        total_cost += -w;

        for (auto [j, new_w]: edges[i]){
            if (-visited[j]  < new_w) continue;
            visited[j] = -new_w;
            heap.push({-new_w, j});
        }
    }

    cout << total_cost;
    return 0;
}
