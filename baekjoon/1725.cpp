#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int N;
int arr[MAX_N];

int step(int s, int e){
    assert(e-s >= 1);
    if (s + 1 == e){
        return arr[s];
    }
    int m = (s + e) >> 1;

    int h = min(arr[m-1], arr[m]);
    int s0 = m - 1;
    int e0 = m + 1;
    int max_box = h * (e0 - s0);
    while (!(s == s0 && e == e0)){
        if (s0 == s){
            h = min(h, arr[e0++]);
        } else if (e0 == e){
            h = min(h, arr[--s0]);
        } else if (arr[e0] > arr[s0-1]){
            h = min(h, arr[e0++]);
        } else {
            h = min(h, arr[--s0]);
        }
        max_box = max(max_box, h * (e0 - s0));
    }

    max_box = max(max_box, step(s, m));
    max_box = max(max_box, step(m, e));
    return max_box;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }

    cout << step(0, N);
}