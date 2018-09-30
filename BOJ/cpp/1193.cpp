#include <stdio.h>

int main(){
  int x;
  int i = 1;
  scanf("%d",&x);
  while (1){
    if (x <= i){
      break;
    }
    x -= i;
    i++;
  }
  i%2==0 ? printf("%d/%d",x,i-x+1) : printf("%d/%d",i-x+1,x);
}
