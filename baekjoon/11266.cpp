#include <bits/stdc++.h>

#define MAX_V 10000

using namespace std;

int discovered[MAX_V];
int is_cut[MAX_V];
int counter = 0;
vector<int> graph[MAX_V];

// Return value: most recently visited node number
int dfs(int x, int is_root){
    discovered[x] = ++counter;
    int ret = discovered[x];

    int child = 0;
    for (int next: graph[x]){
        if (!discovered[next]){
            child += 1;
            int low = dfs(next, false);
            if (!is_root && low >= discovered[x]){
                is_cut[x] = true;
            }
            ret = min(ret, low);
        } else {
            ret = min(ret, discovered[next]);
        }
    }

    if (is_root && child >= 2){
        is_cut[x] = true;
    }
    return ret;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int v, e;
    cin >> v >> e;

    for (int _i=0; _i<e; _i++){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=0; i<v; i++){
        if (!discovered[v]){
            dfs(i, true);
        }
    }

    int count = 0;
    for (int i=0; i<v; i++){
        if (is_cut[i]) count += 1;
    }
    cout << count << '\n';

    for (int i=0; i<v; i++){
        if (is_cut[i]) cout << i + 1 << ' ';
    }
}