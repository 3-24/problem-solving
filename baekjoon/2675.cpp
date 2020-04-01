#include <stdio.h>

void repeat(void){
  char arr[21];
  int num;
  scanf("%d %s",&num,&arr);
  int i = 0;
  while(1){
    char c = arr[i];
    if (c=='\0'){
      break;
    }
    for (int j=0;j<num;j++){
      printf("%c",c);
    }
    i++;
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d",&T);
  for (int i=0;i<T;i++){
    repeat();
  }
  return 0;
}
