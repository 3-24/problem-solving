#include <stdio.h>

int main(){
  int tmp;
  scanf("%d",&tmp);
  char arr[101];
  scanf("%s", arr);
  int sum = 0;
  for (int i=0;i<tmp;i++){
    sum += arr[i] - '0';
  }
  printf("%d",sum);
}
