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
  scanf("%d",&m);
  scanf("%d",&n);
  int i,sum=0,first_prime;
  for (i=m;i<=n;i++){
    if (isPrime(i)){
      if (!sum){
        first_prime = i;
      }
      sum += i;
    }
  }
  if (!sum){
    printf("-1");
  }
  else{
    printf("%d\n%d",sum,first_prime);
  }
}
