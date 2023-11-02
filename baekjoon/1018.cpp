#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool chessboard[51][51];


int find_num_recoloring(int x, int y){
    int count1 = 0;
    int count2 = 0;
    for (int i=x; i<x+8; i++){
        for (int j=y; j<y+8;j++){
            if (chessboard[i][j] == (i+j) % 2) count1++;
            else count2++;
        }
    }
    return min(count1, count2);
}


void solve(){
    int m, n;
    cin >> m >> n;

    for (int i=0;i<m;i++){
        string s;
        cin >> s;
        for (int j=0;j<n;j++){
            if (s[j] == 'B'){
                chessboard[i][j] = 0;
            } else chessboard[i][j] = 1;
        }
    }

    int min_recoloring = INT_MAX;

    for (int x=0;x<=m-8;x++){
        for (int y=0;y<=n-8;y++){
            min_recoloring = min(min_recoloring, find_num_recoloring(x,y));
        }
    }
    cout << min_recoloring;
    return;
}

int main(){
    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}