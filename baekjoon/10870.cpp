#include <stdio.h>
#define MAX_INPUT 20

int main(){
    int n, fibo[MAX_INPUT+1];
    scanf("%d",&n);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i=2;i<=n;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    printf("%d\n",fibo[n]);
    return 0;
}