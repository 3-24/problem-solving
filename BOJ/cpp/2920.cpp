#include <stdio.h>

int main(){
  int arr[8];
  int state,i;
  for (i=0;i<8;i++){
    scanf("%d",&arr[i]);
  }
  for (i=1;i<8;i++){
    if (i == 1){
      if (arr[1] > arr[0]){
        state = 1;
      }
      else{
        state = -1;
      }
    }
    else{
      if (state == 1){
        if (arr[i]<arr[i-1]){
          printf("mixed");
          return 0;
        }
      }
      else if (state == -1){
        if (arr[i] > arr[i-1]){
          printf("mixed");
          return 0;
        }
      }
    }
  }
  state == 1 ? printf("ascending") : printf("descending");
  return 0;
}
