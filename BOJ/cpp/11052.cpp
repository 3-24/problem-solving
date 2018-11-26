#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int i, arr[n+1],D[n+1];
    for (i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for (i=0;i<=n;i++){
        if (i==0){
            D[i] = 0;
        }
        else {
            int m = 0;
            for (int j = 1; j<=i; j++) {
                m = max(m, arr[j] + D[i - j]);
            }
            D[i] = m;
        }
    }
    printf("%d",D[n]);
    return 0;
}