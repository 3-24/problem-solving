#include <stdio.h>
#include <stack>
using namespace std;

int main(){
  int a[10];
  for (int i=0;i<10;i++){
    a[i] = i;
  }
  int (*p)[10] = &a;
  //printf("%d",(*p)[3]);
  printf("%d",*p[3]);
}
