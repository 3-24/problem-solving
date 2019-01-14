#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int Data[n]={0,}, initSum = 0;
    for (int i=0;i<n;i++){
        cin >> Data[i];
        initSum += Data[i];
    }

    int output = 0;
    for (int b=0;b<k;b++){
        int sum = initSum, i=0;
        while(b+i*k <n){
            sum -= Data[b+i*k];
            i++;
        }
        sum = abs(sum);
        if (output < sum) output = sum;
    }
    cout << output;
    return 0;
}