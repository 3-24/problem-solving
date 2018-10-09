#include <stdio.h>

int main(){
  int n,arrCount[10001],i,d;
  for (i=0;i<10001;i++){
    arrCount[i] = 0;
  }
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&d);
    arrCount[d]++;
  }
  for (i=0;i<10001;i++){
    while (arrCount[i]--){
      printf("%d\n",i);
    }
  }
}
