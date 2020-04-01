#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int t,m;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&m);
        int doll[m+1][2], D[m+1];
        for (int i=0;i<m;i++){
            scanf("%d %d",&doll[i][0], &doll[i][1]);
        }
        qsort(doll,m,sizeof(int)*2,compare);
        for (int i=0;i<m;i++){
            D[i] = 1;
            for (int j=0;j<i;j++){
                if (doll[i][1] <= doll[j][1] || doll[i][0] == doll[j][0]){
                    D[i] = max(D[j] + 1, D[i]);
                }
            }
        }
        printf("%d\n",D[m-1]);
    }
    return 0;
}