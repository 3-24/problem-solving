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
  int T,n,i;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for (i=n/2;i>1;i--){
      if (isPrime(i) && isPrime(n-i)){
        break;
      }
    }
    printf("%d %d\n",i,n-i);
  }
}
