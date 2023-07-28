#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // lis_end[i]: Minimum element for lis with length i+1
    vector<int> lis_end;
    vector<vector<array<int, 3>>> lis_log;          // value, prev i, prev j
    
    while (n--){
        int x;
        cin >> x;
        auto it = lower_bound(lis_end.begin(), lis_end.end(), x);
        int i = it - lis_end.begin();
        int prev_i = -1, prev_j = -1;
        if (i >= 1){
            prev_i = i - 1;
            prev_j = size(lis_log[i-1]) - 1;
        }
        array<int, 3> A({x, prev_i, prev_j});

        if (it == lis_end.end()){
            lis_end.push_back(x);
            lis_log.push_back(vector<array<int, 3>>({A}));
        }
        else if (*it > x){
            *it = x;
            lis_log[i].push_back(A);
        }
    }

    int l = lis_end.size();
    
    cout << lis_end.size() << '\n';
    stack<int> lis;
    array<int, 3> elem = lis_log[l-1][0];
    while(true){
        lis.push(elem[0]);
        if (elem[1] == -1) break;
        elem = lis_log[elem[1]][elem[2]];
    }

    while(!lis.empty()){
        int x = lis.top();
        lis.pop();
        cout << x << ' ';
    }

    cout << '\n';
    return 0;
}