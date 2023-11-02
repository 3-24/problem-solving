#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n, m;
    cin >> n >> m;
    auto arr = new int[1025][1025];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            if (i == 0 || j == 0) arr[i][j] = 0;
            else {
                arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            }
        }
    }

    while(m--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        cout << arr[x2][y2] -arr[x1][y2] - arr[x2][y1] + arr[x1][y1] << '\n';
    }

    delete[] arr;

    return 0;
}