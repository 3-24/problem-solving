#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
long b;
int arr[38][6][6]; // log_2(100,000,000,000) = 36.54...

int main(){
    cin >> n >> b;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[0][i][j];
        }
    }

    long mult = 1;
    int ind = 0;
    while(true){
        if (mult * 2 > b) break;
        ind++;
        mult *= 2;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                    arr[ind][i][j] += arr[ind-1][i][k] * arr[ind-1][k][j];
                    arr[ind][i][j] %= 1000;
                }
            }
        }
        
    }

    int ans_mult[5][5];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j) ans_mult[i][j] = 1;
            else ans_mult[i][j] = 0;
        }
    }

    while (b != 0){
        if (mult > b){}
        else {
            b -= mult;
            int newmult[5][5];
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    newmult[i][j] = 0;
                    for (int k=0; k<n; k++){
                        newmult[i][j] += ans_mult[i][k] * arr[ind][k][j];
                        newmult[i][j] %= 1000;
                    }
                }
            }
            memcpy(&ans_mult[0][0], &newmult[0][0], sizeof ans_mult);
        }
        mult /= 2;
        ind--;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << ans_mult[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}