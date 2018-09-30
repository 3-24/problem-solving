#include <stdio.h>

int isArithmetic(int n){
    int arr[4];
    int i = 0;
    while(n != 0){
        arr[i] = n % 10;
        n = n / 10;
        i++;
    }
    int d;
    for(int j=1;j<i;j++){
      if (j==1){
        d=arr[1]-arr[0];
      }
      else{
        if (arr[j]-arr[j-1] != d){
          return 0;
        }
      }
    }
    return 1;

}

int main(){
  int N;
  int count = 0;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    if (isArithmetic(i) == 1){
      count++;
    }
  }
  printf("%d",count);
}
