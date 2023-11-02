#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int D[1001];
    D[0] = 1;
    D[1] = 1;
    for (int i=2;i<=n;i++){
        D[i] = (2*D[i-2] + D[i-1])%10007;
    }
    printf("%d",D[n]);
    return 0;
}