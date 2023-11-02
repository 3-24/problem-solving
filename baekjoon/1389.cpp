#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[101][101];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = 400;      // large number
        }
    }

    while (m--){
        int x,y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for (int i=1; i<=n; i++){
        for (int x=1; x<=n; x++){
            for (int y=1; y<=n; y++){
                int cost = arr[x][i] + arr[i][y];
                if (arr[x][y] > cost){
                    arr[x][y] = cost;
                    arr[y][x] = cost;            
                }
            }
        }
    }

#ifndef ONLINE_JUDGE
    for (int x=1; x<=n; x++){
        for (int y=1; y<=n; y++){
            cerr << arr[x][y] << ' ';
        }
        cerr << '\n';
    }
#endif

    int min_cavin = INT_MAX;
    int min_person = -1;
    for (int i=1; i<=n; i++){
        int cavin_sum =0;
        for (int j=1; j<=n; j++){
            cavin_sum += arr[i][j];
        }
        if (cavin_sum < min_cavin){
            min_cavin = cavin_sum;
            min_person = i;
        }
    }

    cout << min_person;
    return 0;
}