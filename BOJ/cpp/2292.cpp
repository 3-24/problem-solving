#include <stdio.h>

int main(){
  int n;
  int a = 1;
  int i = 0;
  scanf("%d",&n);
  while (n > 0){
    n -= a;
    i++;
    a = 6*i;
  }
  printf("%d",i);
}
