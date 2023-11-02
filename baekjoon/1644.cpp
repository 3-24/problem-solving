#include <bits/stdc++.h>
using namespace std;

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    faster
    int n;
    scanf("%d", &n);
    bool sieve[4000001];
    memset(sieve, true, sizeof(sieve));
    for (int p=2; p*p <= n; p++){
        if (sieve[p]){
            for (int i=p*p; i<=n; i+=p){
                sieve[i] = false;
            }
        }
    }
    int sum = 0;
    int count = 0;
    queue<int> consective_primes;
    for (int p=2; p<=n; p++){
        if (sieve[p]){
            sum += p;
            consective_primes.push(p);
            while (sum > n){
                sum -= consective_primes.front();
                consective_primes.pop();
            }
            if (sum == n){
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
