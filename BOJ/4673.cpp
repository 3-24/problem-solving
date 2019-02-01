#include<stdio.h>

int pow10(int x){
  int prod = 1;
  for (int i=0;i<x;i++){
    prod *= 10;
  }
  return prod;
}

int d(int n){
  int sum = n;
  int i = 0;
  while (1){
    if (n >= pow10(i)){
      sum += n % pow10(i+1)/pow10(i);
      i++;
    }
    else{
      return sum;
    }
  }
}

int main(void){
  int arr[20000];
  int i;
  for (i=1;i<=10000;i++){

    arr[d(i)] = 1;
  }
  for (i=1;i<=10000;i++){
    if (arr[i] != 1){
      printf("%d\n",i);
    }
  }
  return 0;
}
