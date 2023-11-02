#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int n,number_to_push;
    char arr[6];
    scanf("%d",&n);
    queue <int> q;
    while(n--){
        scanf("%s",arr);
        if (!strcmp(arr,"push")){
            scanf("%d\n",&number_to_push);
            q.push(number_to_push);
        }
        else if (!strcmp(arr,"pop")){
            if (!(q.empty())){
                printf("%d\n",q.front());
                q.pop();
            }
            else{
                printf("-1\n");
            }
        }
        else if (!strcmp(arr,"size")){
            printf("%zu\n",q.size());
        }
        else if (!strcmp(arr,"empty")){
            printf("%d\n",q.empty());
        }
        else if (!strcmp(arr,"front")){
            if (!(q.empty())){
                printf("%d\n",q.front());
            }
            else{
                printf("-1\n");
            }
        }
        else if (!strcmp(arr,"back")){
            if (!(q.empty())){
                printf("%d\n",q.back());
            }
            else {
                printf("-1\n");
            }
        }
    }
}