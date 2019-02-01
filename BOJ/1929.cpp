#include <stdio.h>
#include <math.h>

int isPrime(int m){
  if (m == 1){
    return 0;
  }
  int t = (int)(pow(m,0.5));
  for (int i=2;i<=t;i++){
    if (!(m % i)){
      return 0;
    }
  }
  return 1;
}

int main(){
  int m,n;
  scanf("%d %d",&m,&n);
  int i;
  for (i=m;i<=n;i++){
    if (isPrime(i)){
      printf("%d\n",i);
    }
  }
  return 0;
}
