#include <bits/stdc++.h>
typedef long long ll;

ll factorial(ll x, ll q){
    ll prod = 1;
    for (int i=1 ; i<=x;i++){
        prod *= i;
        prod %= q;
    }
    return prod;
}

ll power(ll x, ll e,ll q){
    ll expArr[40], valueArr[40], sum = e, result = 1;
    expArr[1] = x;
    valueArr[1] = 1;
    int i=1;
    while (true){
        if (valueArr[i] > e){
            break;
        }
        i++;
        expArr[i] = (expArr[i-1] * expArr[i-1]) % q;
        valueArr[i] = valueArr[i-1]*2;
    }
    int n;
    while (sum > 0){
        for (n=i;n>0;n--){
            if (valueArr[n] <= sum){
                sum -= valueArr[n];
                result = (result * expArr[n]) % q;
                break;
            }
        }
    }
    return result;
}

int main(){
    ll p = 1000000007, n,k; // 1 <= n <= 4000000, 0<=k<=n
    scanf("%lld %lld",&n,&k);
    printf("%lld", (factorial(n,p) * power((factorial(k,p) * factorial(n-k,p))%p, p-2, p))%p);
    return 0;
}