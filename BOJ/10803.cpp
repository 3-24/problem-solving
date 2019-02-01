#include <stdio.h>
#include <algorithm>
#include <limits.h>
#define MAX_N 10000
#define MAX_M 100

int cut[MAX_N+1][MAX_M+1];

void D(int a, int b){
    if (a==b){
        cut[a][b] = 1;
    }
    else if (3*a >= b*b){
        cut[a][b] = cut[a-b][b] + 1;
    }
    else if (3*b >= a*a){
        cut[a][b] = cut[a][b-a] + 1;
    }
    else{
        cut[a][b] = INT_MAX;
        for (int i=1;i<=a/2;i++){
            cut[a][b] = std::min(cut[a][b],cut[i][b]+cut[a-i][b]);
        }
        for (int j=1;j<=b/2;j++){
            cut[a][b] = std::min(cut[a][b], cut[a][b-j]+cut[a][j]);
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            D(i,j);
        }
    }
    printf("%d",cut[n][m]);

    return 0;
}