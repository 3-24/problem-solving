#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};

struct point P[100000];

bool comp_two_points(struct point a, struct point b){
    if (a.y == b.y){
        return b.x > a.x;
    }
    return b.y > a.y;
}

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> P[i].x >> P[i].y;
    }
    sort(P, P+n, comp_two_points);

    for (int i=0;i<n;i++){
        cout << P[i].x << ' ' << P[i].y << '\n';
    }
    return 0;
}