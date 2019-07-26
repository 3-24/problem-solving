#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> obstacles;

int count_path(int c1, int c2, int Xh, int Yh, int t){
    if (c1 == Xh && c2 == Yh) return 1;
    if (Xh + Yh - c1 - c2 > t) return 0;

    long long int m = 0;
    if (obstacles.find(make_pair(c1-1,c2)) == obstacles.end()) m += count_path(c1-1,c2,Xh,Yh,t-1);
    if (obstacles.find(make_pair(c1+1,c2)) == obstacles.end()) m += count_path(c1+1,c2,Xh,Yh,t-1);
    if (obstacles.find(make_pair(c1,c2-1)) == obstacles.end()) m += count_path(c1,c2-1,Xh,Yh,t-1);
    if (obstacles.find(make_pair(c1,c2+1)) == obstacles.end()) m += count_path(c1,c2+1,Xh,Yh,t-1);

    m %= 1000000007;

    return (int)m;
}

int main(){

    int Xs,Ys,t,n,Xh,Yh;

    cin >> Xs >> Ys;
    cin >> t;
    cin >> Xh >> Yh;
    cin >> n;

    for (int i=0;i<n;i++){
        int c1,c2;
        cin >> c1 >> c2;
        obstacles.insert(make_pair(c1,c2));
    }

    int temp = count_path(Xs,Ys,Xh,Yh,t);

    cout << temp;
    return 0;
}
