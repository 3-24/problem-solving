#include <stdio.h>
#define MAX_NUM 10000

int main(){
  int n;
  scanf("%d",&n);
  int arrNum[n],arrCount[MAX_NUM+1],arrSorted[n],i;
  for (i=0;i<MAX_NUM+1;i++){
    arrCount[i] = 0;
  }
  for (i=0;i<n;i++){
    scanf("%d",&arrNum[i]);
    arrCount[arrNum[i]]++;
  }
  for (i=1;i<10001;i++){
    arrCount[i]+=arrCount[i-1]; // summation seq
  }
  i = n; // final index
  int d;
  while (i>0){
    i--;
    d = arrNum[i];
    arrCount[d]--;
    arrSorted[arrCount[d]] = d;
  }
  for (i=0;i<n;i++){
    printf("%d\n",arrSorted[i]);
  }
  return 0;
}
