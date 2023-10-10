#include <bits/stdc++.h>

using namespace std;

int n, w;

pair<int, int> wontagon[10000];
int dp_full[10000], dp_upper_half[10000], dp_lower_half[10000];

void dp(bool no_merge_upper, bool no_merge_lower){
    for (int i=1; i<n; i++){
        bool cond1 = !(i == 1 && no_merge_upper) && wontagon[i].first + wontagon[i-1].first <= w;
        bool cond2 = !(i == 1 && no_merge_lower) && wontagon[i].second + wontagon[i-1].second <= w;
        dp_upper_half[i] = 1 + dp_full[i-1];
        if (cond1){
            dp_upper_half[i] = min(dp_upper_half[i], dp_lower_half[i-1] + 1);
        }
        dp_lower_half[i] = 1 + dp_full[i-1];
        if (cond2){
            dp_lower_half[i] = min(dp_lower_half[i], dp_upper_half[i-1] + 1);
        }

        dp_full[i] = min(dp_upper_half[i], dp_lower_half[i]) + 1;
        if (wontagon[i].first + wontagon[i].second <= w){
            dp_full[i] = min(dp_full[i], dp_full[i-1] + 1);
        }
        if (cond1 && cond2){
            dp_full[i] = min(dp_full[i],((i == 1) ? 0 : dp_full[i-2]) +  2);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> w;
        for (int i=0; i<n; i++){
            cin >> wontagon[i].first;
        }    
        for (int i=0; i<n; i++){
            cin >> wontagon[i].second;
        }

        int res = INT_MAX;

        dp_full[0] = (wontagon[0].first + wontagon[0].second <= w) ? 1 : 2;

        if (n == 1){
            cout << dp_full[0] << '\n';
            continue;
        }

        dp_upper_half[0] = 1;
        dp_lower_half[0] = 1;
        dp(false, false);

        res = min(res, dp_full[n-1]);

        bool cond_upper = (wontagon[n-1].first + wontagon[0].first <= w);
        bool cond_lower = (wontagon[n-1].second + wontagon[0].second <= w);

        if (cond_upper){
            dp_full[0] = 1;
            dp_upper_half[0] = 0;
            dp_lower_half[0] = 1;
            dp(true, false);
            res = min(res, dp_lower_half[n-1] + 1);
        }

        if (cond_lower){
            dp_full[0] = 1;
            dp_upper_half[0] = 1;
            dp_lower_half[0] = 0;
            dp(false, true);
            res = min(res, dp_upper_half[n-1] + 1);
        }

        if (cond_upper && cond_lower){
            dp_full[0] = 0;
            dp_upper_half[0] = 0;
            dp_lower_half[0] = 0;
            dp(true, true);
            res = min(res, dp_full[n-2] + 2);
        }

        cout << res << '\n';
    }
    
}