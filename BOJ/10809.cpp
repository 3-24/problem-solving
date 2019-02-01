#include <stdio.h>

int main(){
  int arr[123];
  char c;
  int i=0;
  int j;
  for (j=97;j<123;j++){
    arr[j] = -1;
  }
  while(1){
    scanf("%c",&c);
    if (c=='\n'){
      break;
    }
    if (arr[(int)c] == -1){
      arr[(int)c] = i;
    }
    i++;
  }
  for (j=97;j<123;j++){
    printf("%d ",arr[j]);
  }
}
