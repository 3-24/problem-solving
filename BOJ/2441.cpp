#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  for (int i=n;i>0;i--){
    for (int j=i;j<n;j++){
      printf(" ");
    }
    for (int j=0;j<i;j++){
      printf("*");
    }
    printf("\n");
  }
}
