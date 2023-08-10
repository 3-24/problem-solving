#include <bits/stdc++.h>

using namespace std;

int n, m;

int ds[500001];
int ds_size[500001];

int ds_root(int node){
    int r = node;
    while (ds[r] != r){
        r = ds[r];
    }
    return r;
}

bool ds_union(int n1, int n2){
    int r1 = ds_root(n1);
    int r2 = ds_root(n2);
    if (r1 == r2) return false;
    if (ds_size[r1] > ds_size[r2]){
        swap(r1, r2);
    }
    // r1 size <= r2 size
    ds[r1] = r2;
    if (ds_size[r1] == ds_size[r2]){
        ds_size[r2] += 1;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i=0; i<n; i++){
        ds[i] = i;
        ds_size[i] = 1;
    }

    int r = 0;
    for (int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        if (r != 0) continue;
        if (!ds_union(x, y)){
            r = i;
        }
    }
    cout << r;
    return 0;
}