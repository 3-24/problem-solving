#include <bits/stdc++.h>
using namespace std;
bool checkDiff[100001];


// initialize checkDiff as false
void initDiff(int x){
    for (int i=0;i<=x;i++){
        checkDiff[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; // number of difficulty levels, number of problems, <= 100000
    cin >> n >> m;

    int diff; // new-designed difficulty

    initDiff(n);
    int count = 0;

    while (m--){
        cin >> diff;

        // if false
        if (!checkDiff[diff]){
            count++;
            checkDiff[diff] = true;
        }

        // if all difficulty is ready
        if (count == n){
            initDiff(n);
            count = 0;
            cout << 1;
        }

        // if not ready
        else cout << 0;
    }
    return 0;
}