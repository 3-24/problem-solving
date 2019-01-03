#include <bits/stdc++.h>
using namespace std;

int factorial(int x){
    int prod = 1;
    for (int i=1;i<=x;i++){
        prod *= i;
    }
    return prod;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d\n",factorial(n)/(factorial(k)*factorial(n-k)));
    return 0;
}