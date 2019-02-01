#include <bits/stdc++.h>
using namespace std;

int calcValue(int x,int y){
    int l = max(abs(x),abs(y));
    int f = (2*l+1)*(2*l+1);
    if (x == l) return f - (l-y);
    else if (y == -l) return f - (2*l+1) + (x-l);
    else if (x == -l) return f - (2*l+1)*2 - (y+l);
    else return f - (2*l+1)*3 - (x+l);
}

int getLength(int n){
    int count = 0;
    while (n){
        count++;
        n %= 10;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2; // abs value <= 5000, 0<=r2-r1<=49 , 0<=c2-c1 <= 49
    int D[r2-r1+1][c2-c1+1], space = 0;
    for (int i=0;i<r2-r1+1;i++){
        for (int j=0;j<c2-c1+1;j++){
            int x = i+r1;
            int y = j+c1;
            D[i][j] = calcValue(x,y);
            space = max(space,getLength(D[i][j]));
        }
    }
    for (int i=0;i<r2-r1+1;i++){
        for (int j=0;j<c2-c1+1;j++){
            cout << setw(space) << D[i][j];
        }
        cout << endl;
    }
    return 0;
}