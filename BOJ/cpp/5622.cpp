#include <stdio.h>

int dial_time(int n){
  return n+1;
}

int alphabet_to_dial(char c){
  int n = (int) c - 65;
  if (n <= 15){
    return (n/3) + 2;
  }
  else if (n<19){
    return 7;
  }
  else if (n < 22){
    return 8;
  }
  else{
    return 9;
  }
}

int main(){
  int t = 0;
  char arr[16];
  scanf("%s",&arr);
  int i = 0;
  while(arr[i] != '\0'){
    t += dial_time(alphabet_to_dial(arr[i]));
    i++;
  }
  printf("%d",t);
}
