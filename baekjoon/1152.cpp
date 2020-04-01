#include <stdio.h>

int main(){
  char arr[1000001];
  int count = 0;
  int countactive = 1;
  char s;
  while (1){
    scanf("%c",&s);
    if (s=='\n'){
      break;
    }
    else if (s==' '){
      countactive = 1;
    }
    else if (countactive == 1){
      count++;
      countactive = 0;
    }
  }
  printf("%d",count);
  return 0;
}
