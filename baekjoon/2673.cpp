#include <bits/stdc++.h>

using namespace std;

#define fasterio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int max_nodes = 100;

int dp[max_nodes][max_nodes];
int cost[max_nodes][max_nodes];

int main(){
    fasterio();
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        cost[a][b] = cost[b][a] = 1;
    }

    for (int i=0; i<max_nodes; i++){
        for (int j=i-1; j>=0; j--){
            for (int k=j; k<i; k++){
                dp[j][i] = max(dp[j][i], cost[j][i] + dp[j][k] + dp[k][i]);
            }
        }
    }

    cout << dp[0][max_nodes-1] << '\n';
    return 0;
}