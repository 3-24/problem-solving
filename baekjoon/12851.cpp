#include <bits/stdc++.h>
using namespace std;

int n, k;

int visited[100002];

int main(){
    scanf("%d %d", &n, &k);
    queue<pair<int, int>> nodes;
    nodes.push({n, 0});
    int count = 0;
    int min_length = INT_MAX;
    while (!nodes.empty()){
        auto [node, length] = nodes.front();
        if (length > min_length) break;
        nodes.pop();
        visited[node] = true;
        if (node == k){
            count++;
            min_length = length;
        }
        int cands[3] = {node-1, node+1, node<<1};
        for (int cand: cands){
            if (cand < 0 || cand > 100000 || visited[cand]) continue;
            nodes.push({cand, length+1});
        }
    }
    printf("%d\n%d\n", min_length, count);
    return 0;
}