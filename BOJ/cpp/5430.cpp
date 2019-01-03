#include <bits/stdc++.h>
using namespace std;
#define P_MAX 100000


int main(){
    int T; // number of test cases
    scanf("%d",&T);

    while (T--){
        char P[P_MAX+1]; // function. ex) RDD
        scanf("%s\n",P);

        int n; // length(dq)
        deque <int> dq;
        scanf("%d\n[",&n);
        int e, x=0; // e for pop
        bool error = false, reversed = false;

        // reading input array
        while(true){
            char c;
            scanf("%c",&c);
            if ('0' <= c && c <= '9'){
                x = x * 10 + (c-'0');
            }
            else{
                if (x>0) dq.push_back(x);
                if (c == ']') break;
                x = 0;
            }
        }

        int ind = 0; // index
        while (true){
            if (P[ind] == 'R') reversed = !reversed;
            else if (P[ind] == 'D'){
                if (dq.empty()){
                    error = true;
                    printf("error\n");
                    break;
                }
                else if (!reversed) dq.pop_front();
                else dq.pop_back();
            }
            else break;
            ind += 1;
        }

        if (!error) {
            if (dq.empty()){
                printf("[]\n");
            }
            else {
                printf("[");
                if (!reversed) {
                    while (true) {
                        e = dq.front();
                        printf("%d", e);
                        dq.pop_front();
                        if (dq.empty()) {
                            break;
                        }
                        printf(",");
                    }
                } else {
                    while (true) {
                        e = dq.back();
                        printf("%d", e);
                        dq.pop_back();
                        if (dq.size() == 0) break;
                        printf(",");
                    }
                }
                printf("]\n");
            }
        }
    }
    return 0;
}