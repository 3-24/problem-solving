#include <bits/stdc++.h>

int main(){
    int n;
    long long prod = 1;
    scanf("%d",&n);
    for (long long i=1;i<=n;i++) {
        prod *= i;
    }
    printf("%lld",prod);
    return 0;
}