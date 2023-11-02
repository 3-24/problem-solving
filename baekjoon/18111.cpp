#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int m, n, b;
    cin >> m >> n >> b;
    int min_h, max_h;
    min_h = INT_MAX;
    max_h = 0;
    int arr[501][501];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
            min_h = min(min_h, arr[i][j]);
            max_h = max(max_h, arr[i][j]);
        }
    }

    int time_sol, height_sol;
    time_sol = INT_MAX;
    for (int h=min_h; h < max_h+1; h++){
        int destroy_count = 0;
        int build_count = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (arr[i][j] >= h) destroy_count += arr[i][j]-h;
                else build_count += h - arr[i][j];
            }
        }   
        if (build_count > b + destroy_count) break;
        int time = build_count + destroy_count * 2;
        if (time_sol >= time){
            time_sol = time;
            height_sol = h;
        }
    }

    cout << time_sol << ' ' << height_sol;

    return 0;
}