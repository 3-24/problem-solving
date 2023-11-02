#include <bits/stdc++.h>
using namespace std;

vector<int> graph[32002];
int from_count[32002];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    unordered_set<int> root_nodes;
    for (int i=1; i<=n; i++){
        root_nodes.insert(i);
    }
    
    while (m--){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        from_count[b] += 1;
        root_nodes.erase(b);
    }

    priority_queue<int> pq;

    for (int root_node : root_nodes){
        pq.push(-root_node);
    }

    while (!pq.empty()){
        int b = pq.top();
        pq.pop();
        int node = -b;
        cout << node << ' ';
        for (auto to_node: graph[node]){
            from_count[to_node] -= 1;
            if (from_count[to_node] == 0){
                pq.push(-to_node);
            }
        }
    }

    return 0;
}
