#include <stdio.h>

int main(){
  int n,score;
  scanf("%d",&n);
  int max = 0;
  int arr[n];
  for (int i=0;i<n;i++){
    scanf("%d",&score);
    if (score > max){
      max = score;
    }
    arr[i] = score;
  }
  float m = max;
  float sum = 0;
  for (int i=0;i<n;i++){
    sum += arr[i]/m * 100;
  }
  printf("%f",sum/n);
  return 0;
}
