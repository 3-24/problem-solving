#include <bits/stdc++.h>

int main(){
    long long n,k;
    while (true){
        long long ans = 1, div = 1;
        scanf("%lld %lld",&n,&k);
        if (n ==0 && k == 0){
            break;
        }
        if (n-k < k) k = n-k;
        while(k--){
            ans *= n--;
            ans /= div++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}