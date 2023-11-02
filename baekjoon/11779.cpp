#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> bus[1001];
int dists[1001];
int parent[1001];

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int main(){
    int n,m;
    scanf("%d\n%d", &n, &m);
    int start, end, cost;
    while(m--){
        scanf("%d %d %d", &start, &end, &cost);
        bus[start].push_back({end, cost});
    }

    int path_start, path_end;
    scanf("%d %d", &path_start, &path_end);

    // Dijkstra
    fill(dists, &dists[n+1], INT_MAX);
    dists[path_start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({path_start, 0});
    while (!pq.empty()){
        auto [node, dist] = pq.top();
        pq.pop();
        if (dists[node] < dist || dists[path_end] < dist) continue;
        for (auto [to_node, to_cost] : bus[node]){
            int new_dist = dist + to_cost;
            if (new_dist < dists[to_node] && new_dist < dists[path_end]){
                dists[to_node] = new_dist;
                parent[to_node] = node;
                pq.push({to_node, new_dist});
            }
        }
    }
    printf("%d\n", dists[path_end]);
    list<int> full_path;
    int node = path_end;
    while (node != path_start){
        full_path.push_front(node);
        node = parent[node];
    }
    full_path.push_front(path_start);
    printf("%ld\n", full_path.size());
    for (auto n: full_path){
        printf("%d ", n);
    }
    putchar('\n');
    return 0;
}