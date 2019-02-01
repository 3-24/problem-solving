#include <bits/stdc++.h>

#define MAX_SIZE 32

int binomArr[101][101][MAX_SIZE] = {0,};

int main(){
    int n,m; // 5 <= n <= 100
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        binomArr[i][0][0] = 1;
        binomArr[i][i][0] = 1;
        for (int j=1;j<=i-1;j++){
            for (int k=0;k<MAX_SIZE;k++){
                binomArr[i][j][k] += binomArr[i-1][j-1][k] + binomArr[i-1][j][k];
                if (binomArr[i][j][k] >= 10){
                    binomArr[i][j][k] -= 10;
                    binomArr[i][j][k+1] += 1;
                }
            }
        }
    }
    bool end = false;
    for (int i=MAX_SIZE-1;i>=0;i--){
        if (binomArr[n][m][i] != 0){
            end = true;
        }
        if (end){
            printf("%d",binomArr[n][m][i]);
        }
    }
    return 0;
}