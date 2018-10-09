#include <stdio.h>

int main(void){
  char arr[100];
  scanf("%s",arr);
  bool exitOuterLoop = false;
  for (int i=0;i<10;i++){
    for (int j=0; j<10;j++){
      char x = arr[10*i+j];
      if (x == '\0'){
        exitOuterLoop = true;
        break;
      }
      printf("%c",arr[10*i+j]);
    }
    if (exitOuterLoop == true){
      break;
    }
    printf("\n");
  }
  return 0;
}
