#include <bits/stdc++.h>

using namespace std;

#define STEP_LIMIT 5

int N;

int &item(int A[], int x, int y, int dir){
    if (dir == 0) return A[N*x + y];
    else if (dir == 2) return A[N*x + (N-1) - y];
    else if (dir == 1) return A[N*y + x];
    else return A[N*((N-1) -y) + x];
}

// 0: left
void move(int A[], int dir){
    /*
    cout << dir << '\n';
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << A[N*i + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    // Remove empty
    for (int i=0; i<N; i++){
        int x = 0;
        int y = 1;
        while (x < N && y < N){
            if (item(A, i, x, dir) == 0){
                if (item(A, i, y, dir) == 0){
                    y += 1;
                } else {
                    swap(item(A, i, x, dir), item(A, i, y, dir));
                    x += 1;
                    y += 1;
                }
            } else {
                x += 1;
                if (y <= x) y = x + 1;
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N-1; j++){
            if (item(A, i, j, dir) == 0) continue;
            if (item(A, i, j, dir) == item(A, i, j+1, dir)){
                item(A,i,j,dir) *= 2;
                item(A, i, j+1, dir) = 0;
            }
        }
    }

    // Remove empty
    for (int i=0; i<N; i++){
        int x = 0;
        int y = 1;
        while (x < N && y < N){
            if (item(A, i, x, dir) == 0){
                if (item(A, i, y, dir) == 0){
                    y += 1;
                } else {
                    swap(item(A, i, x, dir), item(A, i, y, dir));
                    x += 1;
                    y += 1;
                }
            } else {
                x += 1;
                if (y <= x) y = x + 1;
            }
        }
    }
    /*
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << A[N*i + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    return;
}

int step(int count, int A[]){
    int max_v = -1;
    if (count == 0){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                max_v = max(max_v, A[N*i + j]);
            }
        }
    } else {
        for (int dir = 0; dir < 4; dir++){
            int *An = (int *)malloc(N*N*sizeof(int));
            memcpy(An, A, N*N*sizeof(int));
            move(An, dir);
            max_v = max(max_v, step(count - 1, An));
            free(An);
        }
    }
    return max_v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int a[N*N];

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> a[N*i + j];
        }
    }

    cout << step(STEP_LIMIT, a);
    

    return 0;
}