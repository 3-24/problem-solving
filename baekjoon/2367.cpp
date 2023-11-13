#include <bits/stdc++.h>

#define fasterio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int MAX_NODES = 302;
int cap[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
vector<int> adj[MAX_NODES];
int N, K, D;

int max_flow(int src, int sink){
    int ret = 0;

    while (true){
        vector<int> visited(2+N+D, -1);
        queue<int> q;
        q.push(src);

        while (!q.empty()){
            int start = q.front();
            q.pop();
            for (int end: adj[start]){
                if (visited[end] != -1) continue;
                if (cap[start][end] > flow[start][end]){
                    visited[end] = start;
                    q.push(end);
                    if (end == sink){
                        break;
                    }
                }
            }
        }

        if (visited[sink] == -1) break;

        int f = INT_MAX;

        for (int v=sink; v != src; v = visited[v]){
            int v_pre = visited[v];
            f = min(f, cap[v_pre][v] - flow[v_pre][v]);
        }

        for (int v=sink; v!=src; v = visited[v]){
            int v_pre = visited[v];
            flow[v_pre][v] += f;
            flow[v][v_pre] -= f;
        }

        ret += f;
    }
    return ret;
}

int main(){
    fasterio();
    // N: # of people
    // D: # of dishes
    // K: Maximum # of dishes one can bring
    cin >> N >> K >> D;

    // source is 0
    // sink is 1
    // person n is 2 + n
    // dish d is 2 + N + d

    for (int d=0; d<D; d++){
        int cap_t;
        cin >> cap_t;
        adj[2+N+d].push_back(1);
        cap[2+N+d][1] = cap_t;
    }

    for (int n=0; n<N; n++){
        int t;
        cin >> t;
        int person_node  = 2 + n;
        adj[0].push_back(person_node);
        adj[person_node].push_back(0);
        cap[0][person_node] = K;
        for (int i=0; i<t; i++){
            int d;
            cin >> d;
            int dish_node = 2 + N + (d - 1);
            adj[person_node].push_back(dish_node);
            adj[dish_node].push_back(person_node);
            cap[person_node][dish_node] = 1;
        }
    }

    cout << max_flow(0, 1) << '\n';
    return 0;
}