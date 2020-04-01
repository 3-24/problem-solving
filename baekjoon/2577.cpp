#include <stdio.h>

int main(){
  int arr[10];
  int i;
  for (i=0;i<10;i++){
    arr[i] = 0;
  }
  int a,b,c,d;
  scanf("%d\n%d\n%d",&a,&b,&c);
  d = a*b*c;
  while (d!=0){
    arr[d%10] ++;
    d=d/10;
  }
  for(i=0;i<10;i++){
    printf("%d\n",arr[i]);
  }
}
