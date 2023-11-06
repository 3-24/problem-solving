#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<unsigned int, unsigned int> segtree[1 << 20 | 1];

int N;

void build(){
    for (int i=N-1; i>0; --i){
        auto [and_1, or_1] = segtree[i << 1];
        auto [and_2, or_2] = segtree[i << 1 | 1];
        segtree[i] = {and_1 & and_2, or_1 | or_2};
    }
}

pair<unsigned int, unsigned int> query(int l, int r){
    unsigned int and_res = UINT32_MAX;
    unsigned int or_res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1){
        if (l & 1){
            auto [and_part, or_part] = segtree[l++];
            and_res &= and_part;
            or_res |= or_part;
        }
        if (r & 1){
            auto [and_part, or_part] = segtree[--r];
            and_res &= and_part;
            or_res |= or_part;
        }
    }
    return {and_res, or_res};
}

int main(){
    int K;
    ll D;
    cin >> N >> K >> D;
    vector<pair<ll, unsigned int>> students;
    for (int i=0; i<N; i++){
        int k;
        ll d;
        cin >> k >> d;
        unsigned int covered_algorithm = 0;
        for (int j=0; j<k; j++){
            int x;
            cin >> x;
            x -= 1;
            covered_algorithm |= (1 << x);
        }
        students.push_back({d, covered_algorithm});
    }

    sort(students.begin(), students.end());

    for (int i=0; i<N; i++){
        int covered = students[i].second;
        segtree[N+i] = {covered, covered};
    }

    build();

    // Sliding window
    int l = 0;
    int r = upper_bound(students.begin(), students.end(), pair<ll, unsigned int>{students[0].first+D, UINT32_MAX}) - students.begin();

    int max_reward = 0;
    while (true){
        auto [and_cov, or_cov] = query(l, r);
        int and_size = popcount(and_cov);
        int or_size = popcount(or_cov);
        max_reward = max(max_reward, (r-l) * (or_size - and_size));
        if (r == N) break;
        l += 1;
        while (r != N && students[r].first - students[l].first <= D){
            r += 1;
        }
    }
    cout << max_reward << '\n';
    return 0;
}