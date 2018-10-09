#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int i = n/5;
  while (i>=0){
    if ((n - 5*i)%3 == 0){
      printf("%d",i+(n-5*i)/3);
      return 0;
    }
    i--;
  }
  printf("-1");
  return 0;
}
