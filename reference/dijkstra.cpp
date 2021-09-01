struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>> graph){
    vector<int> dists(n+1, INT_MAX);
    dists[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push(make_pair(0, start));
    while (!q.empty()){
        auto [dist, node] = q.top();
        q.pop();
        for (auto [to_node, to_dist] : graph[node]){
            int new_dist = dist + to_dist;
            if (new_dist < dists[to_node]){
                dists[to_node] = new_dist;
                q.push(make_pair(new_dist, to_node));
            }
        }
    }
    return dists;
}