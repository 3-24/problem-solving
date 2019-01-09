#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 500

int mapArr[MAX_SIZE+1][MAX_SIZE+1], resultArr[MAX_SIZE+1][MAX_SIZE+1];

int n,m;

int countPath(int a, int b){
    if (resultArr[a][b] != -1){
        return resultArr[a][b];
    }
    int sum = 0;
    if (!(a == 0 && b == 0)){
        if (a != 0 && mapArr[a][b] < mapArr[a-1][b]){
            sum += countPath(a-1,b);
        }
        if (a != n && mapArr[a][b] < mapArr[a+1][b]){
            sum += countPath(a+1,b);
        }
        if (b != 0 && mapArr[a][b] < mapArr[a][b-1]){
            sum += countPath(a,b-1);
        }
        if (b != m && mapArr[a][b] < mapArr[a][b+1]){
            sum += countPath(a,b+1);
        }
    }
    else{
        sum = 1;
    }
    resultArr[a][b] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> heightList;
    cin >> n >> m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> mapArr[i][j];
            resultArr[i][j] = -1;
        }
    }
    cout << countPath(n-1,m-1);
    return 0;
}