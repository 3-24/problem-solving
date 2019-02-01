#include <stdio.h>

int main(){
  int num[9];
  for (int i=0;i<9;i++){
    num[i] = 0;
  }
  char c;
  int sum = 0;

  while (1){
    scanf("%c",&c);
    if (c == '\n'){
      break;
    }
    int r = (int)c - 48;
    r != 9 ? num[r]++ : num[6]++;
    sum++;
  }
  int count = 0;
  while (sum != 0){
    for (int i=0;i<9;i++){
      if (num[i] != 0){
        num[i]--;
        sum -= 1;
      }
    }
    if (num[6] != 0){
      num[6] --;
      sum -= 1;
    }
    count += 1;
  }
  printf("%d",count);
}
