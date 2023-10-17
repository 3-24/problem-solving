#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

int N; 

vector<vector<ll>> mat_mult(vector<vector<ll>> &A, vector<vector<ll>> &B){
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<N; k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }

    return C;
}

vector<vector<ll>> mat_power(vector<vector<ll>> &A, int n){
    assert(n >= 1);
    if (n == 1){
        vector<vector<ll>>C = A;
        return C;
    }
    else {
        vector<vector<ll>> B = mat_power(A, n >> 1);
        vector<vector<ll>> C = mat_mult(B, B);
        if (n & 1){
            C = mat_mult(C, A);
        }
        return C;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, D;
    cin >> T >> N >> D;
    vector<vector<vector<ll>>> vessel_map(T, vector<vector<ll>>(N, vector<ll>(N, 0)));
    for (int t=0; t<T; t++){
        int M;
        cin >> M;
        for (int _=0; _<M; _++){
            ll x, y, z;
            cin >> x >> y >> z;
            vessel_map[t][--x][--y] = z;
        }
    }

    int p = D / T;
    int r = D % T;

    vector<vector<ll>> res(N, vector<ll>(N, 0));
    for (int i=0; i<N; i++){
        res[i][i] = 1;
    }

    if (p >= 1){
        for (int i=0; i<T; i++){
            res = mat_mult(res, vessel_map[i]);
        }
        res = mat_power(res, p);
    }
    for (int i=0; i<r; i++){
        res = mat_mult(res, vessel_map[i]);
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}