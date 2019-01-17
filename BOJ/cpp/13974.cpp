// Knuth Optimization

#include <bits/stdc++.h>
using namespace std;
#define MAX_K 5000

int k, sizeArr[MAX_K+1], sumArr[MAX_K+1], D[MAX_K+1][MAX_K+1], K[MAX_K+1][MAX_K+1];

int intervalSum(int x, int y){
    return ( x == 0 ? sumArr[y] : sumArr[y] - sumArr[x-1] );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){

        int k;
        cin >> k;

        sumArr[0] = 0;

        for (int i=1;i<=k;i++){
            cin >> sizeArr[i]; // <= 10000
            sumArr[i] = sumArr[i-1]+sizeArr[i];
            D[i][i] = 0;
            K[i][i] = i;
        }

        for (int l=1;l<k;l++){
            for (int i=1;i<=k-l;i++){
                int j = i+l;
                D[i][j] = INT_MAX;
                for (int x=K[i][j-1]; x <= min(j, K[i+1][j]+1); x++){
                    int v = D[i][x] + D[x+1][j] + intervalSum(i,j);
                    if (v < D[i][j]){
                        D[i][j] = v;
                        K[i][j] = x;
                    }
                }
            }
        }
        cout << D[1][k] << endl;
    }
    return 0;
}