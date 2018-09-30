#include <stdio.h>

int main(){
  int c,n;
  scanf("%d",&c);
  for (int i=0;i<c;i++){
    scanf("%d",&n);
    int arr[n];
    int sum = 0;
    for (int j=0;j<n;j++){
      scanf("%d",&arr[j]);
      sum += arr[j];
    }
    int greater_then_average = 0;
    for (int j=0;j<n;j++){
      if (arr[j]*n > sum){
        greater_then_average++;
      }
    }
    printf("%.3f%%\n",(float)greater_then_average/n * 100);
  }
}
