#include <stdio.h>

int main(){
  int sum=0;
  int i,num;
  for (i=0;i<5;i++){
    scanf("%d",&num);
    num < 40 ? sum += 40 : sum += num;
  }
  printf("%d",sum/5);
  return 0;
}
