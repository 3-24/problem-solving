#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int a[MAX_N];

int main(){
    int n,x,y;
    cin >> n >> x >> y;

    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    bool flag;

    for (int i=0;i<n;i++){
        flag = false;

        for (int j=max(i-x,0);j<min(i+y+1,n);j++){
            if (i != j && a[i] >= a[j]){
                flag = true;
                break;
            }
        }

        if (!flag){
            cout << i+1;
            return 0;
        }
    }
    return 0;
}
