#include <stdio.h>
#include <math.h>

int isPrime(int m){
  if (m == 1){
    return 0;
  }
  if (m==2){
    return 1;
  }
  int t = (int)(pow(m,0.5));
  for (int i=2;i<=t+1;i++){
    if (!(m % i)){
      return 0;
    }
  }
  return 1;
}

int main(){
  int n,count,i;
  while(1){
    scanf("%d",&n);
    if (n==0){
      return 0;
    }
    count = 0;
    for (i=n+1;i<=2*n;i++){
      if (isPrime(i)){
        count++;
      }
    }
    printf("%d\n",count);
  }
}
