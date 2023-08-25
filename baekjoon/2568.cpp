#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> wires;              
vector<int> lis;                                // lis[i] is minimum tail element of lis with length i+1
vector<vector<pair<int, int>>> lis_mem;         // lis_mem[i][j] is (previous index, value) for ith element
set<int> used_y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        wires.push_back(pair<int, int>{x, y});
    }

    sort(wires.begin(), wires.end());

    for (auto [x, y]: wires){
        auto it = upper_bound(lis.begin(), lis.end(), y);
        int i = it - lis.begin();
        int prev = (i == 0) ? -1 : lis_mem[i-1].size() - 1;

        if (it == lis.end()){
            lis.push_back(y);
            lis_mem.push_back(vector<pair<int,int>>{pair<int,int>(prev, y)});
        } else {
            *it = y;
            lis_mem[i].push_back(pair<int,int>{prev, y});
        }
    }

    if (!lis.empty()){
        int i = lis.size() - 1;
        int j = lis_mem[i].size()-1;
        while (i >= 0){
            used_y.insert(lis_mem[i][j].second);
            j = lis_mem[i][j].first;
            i -= 1;
        }
    }

    cout << N - lis.size() << '\n';
    for (auto [x, y]: wires){
        if (used_y.contains(y)) continue;
        else cout << x << '\n';
    }
}