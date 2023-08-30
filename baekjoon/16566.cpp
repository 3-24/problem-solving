#include <bits/stdc++.h>

using namespace std;

#define MAX_N 4000000

int parent[MAX_N+1];
vector<int> arr;

int find(int node){
    int root = node;
    while (parent[root] != root){
        root = parent[root];
    }
    parent[node] = root;
    return root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int x;

    // mlog(m)
    for (int i=0; i<m; i++){
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    
    for (int i=0; i<m; i++){
        parent[arr[i]] = arr[i];
    }

    while (k--){
        cin >> x;
        auto it1 = upper_bound(arr.begin(), arr.end(), x);
        int root = find(*it1);
        auto it2 = upper_bound(arr.begin(), arr.end(), root);
        if (it2 != arr.end()){
            parent[root] = *it2;
        }
        cout << root << '\n';
    }
    return 0;
}