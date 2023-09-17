#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// T번: Tier and Rank
map<string, pair<int, int>> tiers;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T;
    cin >> N >> T;

    int count = 0;
    for (int i=0; i<T; i++){
        string name, t;
        cin >> name >> t;
        int n;
        if (t.back() == '%'){
            t.pop_back();
            int p = stoi(t);
            n = ((ll)(N - count) * (ll)p) / 100LL;
        } else {
            n = min(stoi(t), N - count);
        }
        tiers[name] = {count, count + n};
        count += n;
    }
    assert(count <= N);
    string t;
    cin >> t;
    if (count != N){
        cout << "Invalid System\n";
    } else {
        if (t.back() >= '1' && t.back() <= '4'){
            int x = t.back() - '1';
            t.pop_back();
            if (!tiers.contains(t)){
                cout << "Liar\n";
            } else {
                int tier_size = tiers[t].second - tiers[t].first;
                int quarter = (tier_size + 3) / 4;
                int tier_start = min(tiers[t].first + quarter * x, tiers[t].second);
                int tier_end = min(tier_start + quarter, tiers[t].second);
                if (tier_start == tier_end){
                    cout << "Liar\n";
                } else {
                    cout << tier_start + 1 << ' ' << tier_end << '\n';
                }
            }
        } else {
            if (!tiers.contains(t) || tiers[t].first == tiers[t].second){
                cout << "Liar\n";
            } else {
                cout << tiers[t].first + 1 << ' ' << tiers[t].second << '\n';
            }
        }
    }
}