#include <stdio.h>

int main(){
  int month, day;
  scanf("%d %d",&month,&day);
  int Cal[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int sum = 0;
  for (int j=0;j<month-1;j++){
    sum += Cal[j];
  }
  sum += day-1;
  const char *R[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
  printf("%s",R[sum%7]);
}
