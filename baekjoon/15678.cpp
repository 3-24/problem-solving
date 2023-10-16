#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll segtree[200001];
int N;

ll query(int l, int r){
    assert(l < r);
    ll res = LLONG_MIN;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1){
        if (l & 1){
            res = max(res, segtree[l++]);
        }
        if (r & 1){
            res = max(res, segtree[--r]);
        }
    }
    return res;
}

void update(int p, ll value){
    segtree[p+N] = value;
    for (p += N; p > 1; p >>= 1){
        segtree[p >> 1] = max(segtree[p], segtree[p ^ 1]);
    }
}

int main(){
    int D;
    cin >> N >> D;
    for (int i=0; i<N; i++){
        ll stone;
        cin >> stone;
        int j = max(i - D, 0);
        if (i == j) update(i, stone);
        else {
            ll prev_max = query(j, i);
            update(i, max(stone, stone+prev_max));
        }
    }

    ll res = LLONG_MIN;
    for (int i=0; i<N; i++){
        res = max(res, segtree[i+N]);
    }
    cout << res << '\n';
}