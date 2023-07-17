#include <bits/stdc++.h>

using namespace std;

int N;
int points[3072][4];
int arr[3072];
int depth[3072];
int num_nodes[3072];

int cross_prod(int x1, int y1, int x2, int y2){
    return (x1*y2 - x2*y1);
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    int res = cross_prod(x1, y1, x2, y2) + cross_prod(x2, y2, x3, y3) + cross_prod(x3, y3, x1, y1);
    if (res > 0) return 1;
    else if (res == 0) return 0;
    else return -1;
}

bool intersect(int i, int j){
    int x1 = points[i][0], y1 = points[i][1], x2 = points[i][2], y2 = points[i][3];
    int x3 = points[j][0], y3 = points[j][1], x4 = points[j][2], y4 = points[j][3];
    int ccw1 = ccw(x1, y1, x3, y3, x2, y2);
    int ccw2 = ccw(x1, y1, x4, y4, x2, y2);
    int ccw3 = ccw(x3, y3, x1, y1, x4, y4);
    int ccw4 = ccw(x3, y3, x2, y2, x4, y4);
    if (ccw1 == ccw2 && ccw3 == ccw4 && ccw1 == 0 && ccw3 == 0){
        // slope of 0 degree
        if (y1 == y2){
            if (x1 > x2) swap(x1, x2);
            if (x3 > x4) swap(x3, x4);
            if (x2 < x3 || x1 > x4) return false;
            return true;
        } else {
            if (y1 > y2) swap (y1, y2);
            if (y3 > y4) swap (y3, y4);
            if (y2 < y3 || y1 > y4) return false;
            return true;
        }
    }
    if (ccw3 == ccw4 || ccw1 == ccw2) return false;
    return true;
}

int ds_root(int a){
    int i = a;
    while (arr[i] != i){
        i = arr[i];
    }
    return i;
}

// Disjoint set
void ds_union(int a, int b){
    int r1 = ds_root(a);
    int r2 = ds_root(b);
    if (r1 == r2) return;
    int d1 = depth[r1];
    int d2 = depth[r2];
    if (d1 >= d2){
        arr[r2] = r1;
        if (d1 == d2){
            depth[r1] += 1;
        }
        num_nodes[r1] += num_nodes[r2];
    }
    else{
        arr[r1] = r2;
        num_nodes[r2] += num_nodes[r1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> points[i][0] >> points[i][1] >> points[i][2] >> points[i][3];
        arr[i] = i;
        depth[i] = 1;
        num_nodes[i] = 1;
    }
    
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            if (intersect(i, j)){
                ds_union(i, j);
            }
        }
    }

    int count = 0;
    int max_size = -1;
    for (int i=0; i<N; i++){
        if (arr[i] == i){
            count += 1;
            max_size = max(max_size, num_nodes[i]);
        }
    }

    cout << count << '\n' << max_size << '\n';
    return 0;
}