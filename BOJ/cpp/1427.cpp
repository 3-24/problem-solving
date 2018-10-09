#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  return *(int *)b - *(int *)a;
}

int main(){
  int arr[11];
  int i = 0;
  int n;
  scanf("%d",&n);
  while (n){
    arr[i] = n % 10;
    i++;
    n/=10;
  }
  qsort(arr,i,sizeof(int),compare);
  for (int j=0;j<i;j++){
    printf("%d",arr[j]);
  }
}
