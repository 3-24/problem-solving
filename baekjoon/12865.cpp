#include <bits/stdc++.h>
using namespace std;

int n, lim;
pair<int ,int> goods[100];
int dp[101][100001];    // DP[i][j]는 0~(i-1)까지를 사용하면서 무게가 j를 넘어가지 않는 가치의 최대

int main(){
    scanf("%d %d", &n, &lim);
    for (int i=0; i<n; i++){
        int weight, value;
        scanf("%d %d", &weight, &value);
        goods[i] = {weight, value};
    }
    for (int i=1; i<=n; i++){
        auto [weight, value] = goods[i-1];
        for (int j=0; j<=lim; j++){
            if (j < weight) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
        }
    }
    printf("%d\n", dp[n][lim]);
    return 0;
}