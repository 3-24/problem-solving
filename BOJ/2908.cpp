#include <stdio.h>

int main(){
  int A[3], B[3];
  int choice;
  int i;
  int n;
  for (i=0;i<3;i++){
    scanf("%1d",&n);
    A[i] = n;
  }
  for (i=0;i<3;i++){
    scanf("%1d",&n);
    B[i] = n;
  }
  for (i=2;i>=0;i--){
    if (A[i] != B[i]){
      if (A[i]> B[i]){
        for (int j=2;j>=0;j--){
          printf("%d",A[j]);
        }
      }
      else{
        for (int j=2;j>=0;j--){
          printf("%d",B[j]);
        }
      }
      return 0;
    }
  }
}
