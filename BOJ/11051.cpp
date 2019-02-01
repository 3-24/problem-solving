#include <bits/stdc++.h>

#define MAX_N 1000

int combArr[MAX_N+1][MAX_N+1];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++){
        combArr[i][0] = 1;
        combArr[i][i] = 1;
        for (int j=1;j<=i-1;j++){
            combArr[i][j] = (combArr[i-1][j-1] + combArr[i-1][j])%10007;
        }
    }
    printf("%d",combArr[n][k]);
    return 0;
}