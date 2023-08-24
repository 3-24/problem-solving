#include <bits/stdc++.h>

using namespace std;

#define MAX_D 1000000000
#define MOD   1000000007
#define NODES 8

typedef long long int ll;

int D;

bool graph[NODES][NODES];
vector<pair<int, int>> edges{
    pair<int, int>{0, 1},
    pair<int, int>{0, 2},
    pair<int, int>{1, 2},
    pair<int, int>{1, 3},
    pair<int, int>{2, 3},
    pair<int, int>{2, 4},
    pair<int, int>{3, 4},
    pair<int, int>{3, 5},
    pair<int, int>{4, 5},
    pair<int, int>{5, 6},
    pair<int, int>{4, 7},
    pair<int, int>{6, 7}
};

map<array<int, 3>, int> mem;

int dp(int start, int end, int n){
    if (n == 0) {
        if (start == end) return 1;
        else return 0;
    } 
    if (n == 1) {
        if (graph[start][end]) return 1;
        else return 0;
    }

    if (end < start) swap(start, end);
    array<int, 3> p{start, end, n};
    if (mem.contains(p)) return mem[p];

    int n0 = n >> 1;
    int n1 = n - n0;
    ll sum = 0;
    for (int mid=0; mid<NODES; mid++){
        sum += ((ll)dp(start, mid, n0) * (ll)dp(mid, end, n1));
        sum %= MOD;
    }
    mem[p] = sum;
    return sum;

}

int main(){
    for (auto p: edges){
        graph[p.first][p.second] = 1;
        graph[p.second][p.first] = 1;
    }
    
    cin >> D;
    cout << dp(0, 0, D);
}
