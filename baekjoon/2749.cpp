#include <stdio.h>
#include <iostream>
using namespace std;
const int mod = 1000000;
const int period = 1500000;
int fibo[period] = {0,1};

int main(){
    long long int n;
    scanf("%lld",&n);
    n = (int)(n % period);
    for (int i=2;i<=n;i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
    }
    printf("%d\n",fibo[n]);
    return 0;
}