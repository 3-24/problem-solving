#include <bits/stdc++.h>
using namespace std;
int checkDiff[100001]={0,};


// initialize checkDiff as false
int initDiff(int x){
    int count = 0;
    for (int i=1;i<=x;i++){
        checkDiff[i] -= 1;
        if (checkDiff[i] != 0) count++;
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; // number of difficulty levels, number of problems, <= 100000
    cin >> n >> m;

    int diff; // new-designed difficulty
    int count = 0;

    for (int r=1;r<=m;r++){
        cin >> diff;

        if (checkDiff[diff] == 0){
            count++;
        }

        checkDiff[diff]++;

        // if all difficulty is ready
        if (count == n){
            count = initDiff(n);
            cout << 1;
        }

        // if not ready
        else cout << 0;
    }
    return 0;
}