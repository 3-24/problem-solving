#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1],D[n+1],i;
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++){
        if (i==0){D[i] = arr[0];}
        else if (i==1){D[i] = arr[0]+arr[1];}
        else if (i==2){D[i] = max({D[i-1],arr[2]+arr[0],arr[2]+arr[1]});}
        else{
            D[i] = max({D[i-1],arr[i]+D[i-2],arr[i]+arr[i-1]+D[i-3]});
        }
    }
    printf("%d",D[n-1]);
    return 0;
}