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
  int n,m;
  scanf("%d",&n);
  int count = 0;
  while (n--){
    scanf("%d",&m);
    if (isPrime(m)){count++;}
  }
  printf("%d",count);
  return 0;
}
