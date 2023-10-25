#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
vector<pair<ll, ll>> segtree;
vector<ll> arr;

void init(int node, int start, int end){
    assert(start < end);
    if (start+1 ==end) segtree[node].second = arr[start];
    else {
        int mid = (start + end) / 2;
        init(node * 2, start, mid);
        init(node * 2 + 1, mid, end);
    }
}

void update(int node, int start, int end, int update_start, int update_end, pair<ll, ll> diff){
    if (start >= update_end || end <= update_start) return;
    if (start >= update_start && end <= update_end){
        segtree[node].first += diff.first;
        segtree[node].second += diff.second + start - update_start;
    } else {
        int mid = (start + end) / 2;
        update(node << 1, start, mid, update_start, update_end, diff);
        update(node << 1 | 1, 
            mid, 
            end, 
            update_start, 
            update_end, 
            diff);
    }
}

ll query(int node, int start, int end, int i){
    if (start + 1 == end){
        assert(start == i);
        return segtree[node].second;
    } else {
        int mid = (start + end) / 2;
        ll count = segtree[node].second + segtree[node].first * (i-start);

        if (i < mid)
            return count + query(node << 1, start, mid, i);
        else
            return count + query(node << 1 | 1, mid, end, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int h = ceil(log2(N));
    segtree = vector<pair<ll, ll>>(1 << (h+1), {0, 0});

    for (int i=0; i<N; i++){
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    init(1, 0, N);

    int q;
    cin >> q;
    while (q--){
        int kind;
        cin >> kind;
        if (kind == 1){
            int start, end;
            cin >> start >> end;
            start -= 1;
            update(1, 0, N, start, end, {1, 1});
        } else {
            assert(kind == 2);
            int y;
            cin >> y;
            y -= 1;
            cout << query(1, 0, N, y) << '\n';
        }
    }
}
