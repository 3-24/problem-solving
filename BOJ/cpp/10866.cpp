#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int T,x;
    char arr[11];
    deque <int> dq;
    scanf("%d",&T);
    while(T--){
        scanf("%s",&arr);
        if (!strcmp(arr,"push_front")){
            scanf("%d",&x);
            dq.push_front(x);
        }
        else if (!strcmp(arr,"push_back")){
            scanf("%d",&x);
            dq.push_back(x);
        }
        else if (!strcmp(arr,"pop_front")){
            if (dq.empty()){
                printf("-1\n");
            }
            else {
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
        else if (!strcmp(arr,"pop_back")){
            if (dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n",dq.back());
                dq.pop_back();
            }
        }
        else if (!strcmp(arr,"size")){
            printf("%d\n",dq.size());
        }
        else if (!strcmp(arr,"empty")){
            printf("%d\n",dq.empty());
        }
        else if (!strcmp(arr,"front")){
            if (dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n",dq.front());
            }
        }
        else if (!strcmp(arr,"back")){
            if (dq.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n",dq.back());
            }
        }
    }
    return 0;
}