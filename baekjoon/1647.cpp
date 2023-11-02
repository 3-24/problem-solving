#include <bits/stdc++.h>
using namespace std;

int n;

struct compare {
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
        return get<2>(a) > get<2>(b);
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin >> n >> m;
    vector<pair<int, int>> graph[100001];
    int a,b,c;
    while(m--){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    unordered_set<int> visited;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> edge_pq;
    visited.insert(1);
    int total_cost = 0;
    for (auto [to_node, cost]: graph[1]){
        edge_pq.push(tuple<int,int,int>{1, to_node, cost});
    }
    int max_cost = INT_MIN;
    while(!edge_pq.empty()){
        auto [from_node, to_node, cost] = edge_pq.top();
        edge_pq.pop();
        if (!visited.contains(to_node)){
            max_cost = max(max_cost, cost);
            visited.insert(to_node);
            total_cost += cost;
            for (auto [new_node, new_cost]: graph[to_node]){
                if (!visited.contains(new_node)){
                    edge_pq.push(tuple<int,int,int>{to_node, new_node, new_cost});
                }
            }
        }
    }

    cout << total_cost-max_cost;
    return 0;
}
