#include <bits/stdc++.h>

using namespace std;

int N, M;
int mem[128];
int cost[128];

map<int, int> dp[128];

int step(int i, int m){
    if (m <= 0) return 0;
    if (i >= N) return 10001;
    if (!dp[i].contains(i)){
        dp[i][m] = min(step(i+1, m), cost[i]+step(i+1, m - mem[i]));
    }
    return dp[i][m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> mem[i];
    }

    for (int i=0; i<N; i++){
        cin >> cost[i];
    }

    cout << step(0, M);
    return 0;
}