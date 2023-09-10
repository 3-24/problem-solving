#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int n;
pair<int, int> segtree[MAX_N*2 + 1];

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (b.first < a.first) return true;
    else if (b.first == a.first && b.second < a.second) return true;
    else return false;
}

void modify(int p, int value){
    segtree[p+n] = {value, p};
    for(p += n; p > 1; p >>= 1){
        segtree[p >> 1] = (cmp(segtree[p], segtree[p ^ 1]) ? segtree[p ^ 1] : segtree[p]);
    }
}

int query(int l, int r){
    pair<int, int> res = {INT_MAX, INT_MAX};
    
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1){
            res = cmp(res, segtree[l]) ? segtree[l] : res;
            l += 1;
        }
        if (r&1){
            r -= 1;
            res = cmp(res, segtree[r]) ? segtree[r] : res;
        }
    }
    return res.second;
}

void build() {
    for (int i=n-1; i>0; --i){
        segtree[i] = (cmp(segtree[i << 1], segtree[i << 1 | 1]) ? segtree[i << 1 | 1] : segtree[i << 1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        segtree[n+i] = {x, i};
    }
    build();
    int m;
    cin >> m;
    while (m--){
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        if (t0 == 1){
            modify(t1-1, t2);
        } else {
            assert(t0 == 2);
            cout << query(t1-1, t2)+1 << '\n';
        }
    }
}