#include <bits/stdc++.h>

using namespace std;

int n;

typedef array<int, 4> state;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin >> n >> w;
    assert( w >= 1);
    state init_state{1, 1, n, n};
    vector<map<state, pair<int, state>>> dp(w+1, map<state, pair<int, state>>());
    dp[0][init_state] = {0, init_state};
    for (int i=1; i<=w; i++){
        int x, y;
        cin >> x >> y;
        for (auto [st, p]: dp[i-1]){
            auto [x1, y1, x2, y2] = st;
            int cost = p.first;
            state s1{x1, y1, x, y};
            int c1 = cost + abs(x2 - x) + abs(y2 - y);
            if (!dp[i].contains(s1) || dp[i][s1].first > c1){
                dp[i][s1] = {c1, st};
            }
            state s2{x2, y2, x, y};
            int c2 = cost + abs(x1 - x) + abs(y1 - y);
            if (!dp[i].contains(s2) || dp[i][s2].first > c2){
                dp[i][s2] = {c2, st};
            }
        }
    }
    int min_cost = INT_MAX;
    state min_state;
    for (auto [s, p]: dp[w]){
        if (min_cost > p.first){
            min_state = s;
            min_cost = p.first;
        }
    }
    cout << min_cost << '\n';

    vector<state> state_log(w, state{0,0,0,0});

    for (int i=w; i>=1; i--){
        state_log[i-1] = min_state;
        min_state = dp[i][min_state].second;
    }
    

    bool rev = false;
    state it_state{1, 1, n, n};
    for (auto new_st: state_log){
        // cout << new_st[0] << ' ' << new_st[1] << ' ' << new_st[2] << ' ' << new_st[3] << '\n';
        if (it_state[0] == new_st[0] && it_state[1] == new_st[1]){
            cout << (rev ? 1 : 2) << '\n';
        } else {
            cout << (rev ? 2 : 1) << '\n';
            rev = !rev;
        }
        it_state = new_st;
    }
}

