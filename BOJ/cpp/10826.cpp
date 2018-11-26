#include <bits/stdc++.h>
using namespace std;
int fibo[2200][10001]={{0,1},{0,0},}; // digit-wised, based on value of 10000th Fibonacci number

int numberOfDigits(int n)
{
    if (n == 1) return 1;
    long double d = (n * log10(1.6180339887498948)) - ((log10(5)) / 2); // using phi = 1.6180339887498948
    return ceil(d);
}

int main(){
    int n;
    scanf("%d",&n);
    int digit = numberOfDigits(n);
    for (int i=2;i<=n;i++){
        for (int j=0;j<digit;j++){
            fibo[j][i] = fibo[j][i-1] + fibo[j][i-2];
        }
        for (int j=0;j<digit-1;j++){
            fibo[j+1][i] += fibo[j][i]/10;
            fibo[j][i] %= 10;
        }
    }
    if (!n){
        printf("0");
    }
    else {
        bool isPrinted = 0;
        for (int k = digit - 1; k >= 0; k--) {
            if (fibo[k][n]) {
                printf("%d", fibo[k][n]);
                isPrinted = 1;
            }
            else if (isPrinted) printf("0");
        }
    }
    return 0;
}