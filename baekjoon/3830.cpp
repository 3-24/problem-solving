#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;
int parent[100001];
ll weight[100001];

pair<int, ll> do_find(int i) {
    if (parent[i] < 0) {
        return {i, 0};
    } else {
        auto [j, w] = do_find(parent[i]);
        parent[i] = j;
        weight[i] = w + weight[i];
        return {parent[i], weight[i]};
    }
}

void do_union(int x, int y, ll w) {
    // w_y = w_x + w
    // w[b] + bw = w[a] + aw + w
    auto [a, aw] = do_find(x);
    auto [b, bw] = do_find(y);

    if (a == b) return;

    if (parent[a] < parent[b]) {
        parent[a] += parent[b];
        parent[b] = a;
        weight[b] = aw - bw + w;
    } else {
        parent[b] += parent[a];
        parent[a] = b;
        weight[a] = bw - aw - w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (int i = 0; i < N; i++) {
            parent[i] = -1;
            weight[i] = 0;
        }

        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == '!') {
                int a, b;
                ll w;
                cin >> a >> b >> w;
                a -= 1;
                b -= 1;
                do_union(a, b, w);
            } else {
                int a, b;
                cin >> a >> b;
                a -= 1;
                b -= 1;
                auto [ap, aw] = do_find(a);
                auto [bp, bw] = do_find(b);

                if (ap != bp)
                    cout << "UNKNOWN";
                else
                    cout << bw - aw;
                cout << '\n';
            }
        }
    }
}