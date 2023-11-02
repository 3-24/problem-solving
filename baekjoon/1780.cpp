#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int arr[10000][10000];

int main(){
    int n;
    cin >> n;
    int counts[3] = {0, 0, 0};
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
            counts[arr[i][j]+1]++;
        }
    }

    while (n != 1){
        for (int i=0; i<n/3; i++){
            for (int j=0; j<n/3; j++){
                set<int> colors;
                for (int x=0; x<3; x++){
                    for (int y=0; y<3; y++){
                        colors.insert(arr[3*i+x][3*j+y]);
                    }
                }
                if (colors.size() == 1){
                    int color = *colors.begin();
                    if (color != 2){
                        counts[color+1] -= 8;
                    }
                    arr[i][j] = color;
                }
                else arr[i][j] = 2;
            }
        }
        n = n /= 3;
    }

    cout << counts[0] << '\n' << counts[1] << '\n' << counts[2];


    return 0;
}