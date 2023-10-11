#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;

#define MAX_DIST 5
#define MOD 1000003
int N;

Matrix mat_mult(Matrix &a, Matrix &b){
    Matrix graph(MAX_DIST*N, vector<ll>(MAX_DIST*N, 0));
    for (int i=0; i<MAX_DIST*N; i++){
        for (int j=0; j<MAX_DIST*N; j++){
            for (int k=0; k<MAX_DIST*N; k++){
                graph[i][j] += a[i][k] * b[k][j];
                graph[i][j] %= MOD;
            }
        }
    }
    return graph;
}

Matrix mat_power(Matrix &a, int x){
    Matrix res;
    if (x == 1) res = a;
    else {
        Matrix b = mat_power(a, x >> 1);
        if (x & 1){
            Matrix b_square = mat_mult(b, b);
            res = mat_mult(b_square, a);
        } else {
            res = mat_mult(b, b);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int S, E, T;
    cin >> N >> S >> E >> T;

    --S; --E;
    Matrix graph(MAX_DIST * N, vector<ll>(MAX_DIST * N, 0));

    for (int i=0; i<N; i++){
        graph[5*i][5*i+1] = 1;
        graph[5*i+1][5*i+2] = 1;
        graph[5*i+2][5*i+3] = 1;
        graph[5*i+3][5*i+4] = 1;
    }

    cin.ignore();

    for (int i=0; i<N; i++){
        int node_from = 5*i + 4;
        for (int j=0; j<N; j++){
            char c = cin.get();
            int cost = c - '0';
            if (cost != 0){
                int node_to = 5*j + 4 - (cost - 1);
                graph[node_from][node_to] = 1;
            }
        }
        cin.ignore();
    }

    Matrix res = mat_power(graph, T);
    cout << res[5*S+4][5*E+4] << '\n';
    return 0;
}