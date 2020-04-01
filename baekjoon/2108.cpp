#include <stdio.h>

int main(){
  int positiveCount[4001],negativeCount[4001],i,n,d;
  scanf("%d",&n);
  for (i=0;i<4001;i++){
    positiveCount[i] = 0;
    negativeCount[i] = 0;
  }
  for (i=0;i<n;i++){
    scanf("%d",&d);
    d >= 0 ? positiveCount[d]++ : negativeCount[-d]++;
  }
  int min=4001,max=-4001,index=0,is_initial = 1,median,mode,mode_val=0,mode_count = 0;
  float sum=0;
  for (i=4000;i>0;i--){
    sum += -i*negativeCount[i];
    index += negativeCount[i];
    if (is_initial && index >= (n+1)/2){
      median = -i;
      is_initial = 0;
    }
    if (mode_val < negativeCount[i]){
      mode = -i;
      mode_val = negativeCount[i];
      mode_count = 0;
    }
    else if (mode_val == negativeCount[i]){
      mode_count++;
      if (mode_count == 1){
        mode = -i;
      }
    }
    if (negativeCount[i]){
      if (-i > max){max = -i;}
      if (-i < min){min = -i;}
    }
  }

  for (i=0;i<4001;i++){
    sum += i * positiveCount[i];
    index += positiveCount[i];
    if (is_initial && index >= (n+1)/2){
      median = i;
      is_initial = 0;
    }
    if (mode_val < positiveCount[i]){
      mode = i;
      mode_val = positiveCount[i];
      mode_count = 0;
    }
    else if (mode_val == positiveCount[i]){
      mode_count++;
      if (mode_count == 1){
        mode = i;
      }
    }
    if (positiveCount[i]){
      if (i > max){max = i;}
      if (i < min){min = i;}
    }
  }
  printf("%.f\n%d\n%d\n%d",sum/n,median,mode,max-min);
  return 0;
}
