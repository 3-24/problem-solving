#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int main(){
  int n;
  scanf("%d",&n);
  int numArr[1001];
  for (int i=0;i<n;i++){
    scanf("%d",&numArr[i]);
  }
  qsort(numArr,n,sizeof(int),compare);
  for (int i=0;i<n;i++){
    printf("%d\n",numArr[i]);
  }
  return 0;
}
