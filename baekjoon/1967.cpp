#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int v;

pair<int, int> find_max_node(int node, vector<vector<pair<int, int>>>arr){
    int dists[10001];
    int visited[10001] = {0, };
    dists[node] = 0;
    queue<int> q;
    q.push(node);
    int max_node = node;
    int max_dist = 0;
    visited[node] =true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (auto p: arr[node]){
            int to_node = p.first;
            if (visited[to_node]) continue;
            int to_distance = p.second;
            dists[to_node] = to_distance + dists[node];
            if (dists[to_node] > max_dist){
                max_dist = dists[to_node];
                max_node = to_node;
            }
            visited[to_node] = true;
            q.push(to_node);
        }
    }

    return make_pair(max_node, max_dist);
}


int main(){
    cin >> v;
    if (v == 1){
        cout << 0;
        return 0;
    }
    vector<vector<pair<int, int>>>arr(v+1, (vector<pair<int, int>>){});

    for (int i=0; i<v-1; i++){
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        arr[node1].push_back(make_pair(node2, weight));
        arr[node2].push_back(make_pair(node1, weight));
    }

    pair<int, int> p1 = find_max_node(1, arr);
    pair<int, int> p2 = find_max_node(p1.first, arr);
    cout << p2.second;

    return 0;
}