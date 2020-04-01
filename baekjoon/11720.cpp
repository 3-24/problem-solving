#include <stdio.h>

int main(){
  int _;
  scanf("%d",&_);
  char arr[_];
  scanf("%s", arr);
  int sum = 0;
  for (int i=0;i<_;i++){
    sum += arr[i] - '0';
  }
  printf("%d",sum);
}
