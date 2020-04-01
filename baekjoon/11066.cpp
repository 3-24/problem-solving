#include <bits/stdc++.h>
using namespace std;
#define MAX_K 500

int k, sizeArr[MAX_K], sumArr[MAX_K], resultArr[MAX_K+1][MAX_K+1];

int calcSum(int x, int y){
    return (x == 0 ? sumArr[y-1] : sumArr[y-1] - sumArr[x-1]);
}

int calcResult(int x,int y){
    if (resultArr[x][y] != -1){
        return resultArr[x][y];
    }
    int min_compare = INT_MAX;
    for (int r=x+1;r<y;r++){
        if (min_compare > calcResult(x,r) + calcResult(r,y)) min_compare = calcResult(x,r) + calcResult(r,y);
    }
    resultArr[x][y] = min_compare + calcSum(x,y);
    return resultArr[x][y];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // 3 <= k <= 500
    cin >> t;
    while(t--){

        cin >> k;
        for (int i=0;i<k;i++){
            memset(resultArr[i],-1,sizeof(int) * (MAX_K+1));
            cin >> sizeArr[i];
            resultArr[i][i+1] = 0;
            if (i == 0) sumArr[i] = sizeArr[i];
            else sumArr[i] = sumArr[i-1] + sizeArr[i];
        }
        memset(resultArr[k],-1,sizeof(int)*(MAX_K+1));
        cout << calcResult(0,k) << endl;

    }


    return 0;
}