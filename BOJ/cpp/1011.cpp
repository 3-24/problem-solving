#include <stdio.h>

int warp(int length){
  int i=0, j=0;
  while (length > 0){
    if (i%2 ==0){
      j++;
    }
    length -= j;
    i++;
  }
  return i;
}

int main(){
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",warp(b-a));
  }
  return 0;
}
