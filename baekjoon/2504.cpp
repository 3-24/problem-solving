#include <stdio.h>
#include <string.h>
#include <stack>
#include <assert.h>
using namespace std;

int errorSum(int a,int b){
  if (!a || !b){
    return 0;
  }
  if (b==1){
    return a;
  }
  return a+b;
}

int repnum(char c){
  if (c == '('){
    return 2;
  }
  else if (c == '['){
    return 3;
  }
  else {
    assert(false);
    return 0;
  }
}

char reppair(char c){
  if (c == '('){
    return ')';
  }
  else if (c == '['){
    return ']';
  } else {
    assert(false);
    return 0;
  }
}

int calc(char s[], int start, int end){
  if (start == end){
    return 1;
  }
  int sum = 0;
  int i = start;
  char c = s[start];
  if (c == '(' || c == '['){
    sum = 1;
    while (1){
      i++;
      if (i>=end){return 0;}
      if (s[i] == c) {sum++;}
      else if (s[i] == reppair(c)){sum--;}

      if (sum == 0){
        return errorSum(calc(s,start+1,i)*repnum(c),calc(s,i+1,end));
      }
    }
  }
  return 0;
}

int main(){
  char s[31];
  scanf("%s",s);
  int n = strlen(s);
  printf("%d",calc(s,0,n));
}