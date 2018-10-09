#include <stdio.h>

int main(){
  int n;
  int arr[100];
  scanf("%d", &n);
  if (n<10){
    arr[0] = n;
    arr[1] = 0;
  }
  else{
    arr[0] = n / 10;
    arr[1] = n % 10;
  }
  int i = 2;
  while (1){
    arr[i] = (arr[i-2] + arr[i-1]) % 10;
    if (arr[i-1] == arr[0] && arr[i] == arr[1] ){
      break;
    }
    i++;
  }
  printf("%d",i-1);
  return 0;
}
