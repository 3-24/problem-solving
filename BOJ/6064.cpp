#include <stdio.h>

int gcd(int a, int b){
  if (b == 0){
    return a;
  }
  else{
    int r = a % b;
    return gcd(b,r);
  }
}

long long int lcm(int a, int b){
  return a*b/gcd(a,b);
}

long long int year(int a, int b, int x, int y){
  long long int L = lcm(a,b);
  for (int i=0;i<=L/x;i++){
    long long int z = x+a*i;
    if ((z-y)%b == 0 && z-y >= 0){
      if (z <= L){
        return z;
      }
    }
  }
  return -1;
}

int main(){
  int T;
  scanf("%d",&T);
  int M,N,x,y;
  while (T--){
    scanf("%d %d %d %d",&M,&N,&x,&y);
    printf("%lld\n",year(M,N,x,y));
  }
  return 0;
}
