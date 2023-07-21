#include <bits/stdc++.h>

using namespace std;

int N;
long long int arr[5001];

pair<int, int> search(int start){
    long long int min_lv2 = INT64_MAX;
    int i = start + 1;
    int j = N - 1;
    int min_i, min_j;
    while (i < j){
        long long int min_lv3 = abs(arr[start] + arr[i] + arr[j]);
        while (i < j-1){
            long long int a = abs(arr[start] + arr[i] + arr[j-1]);
            if (a <= min_lv3){
                min_lv3 = a;
                j = j-1;
            } else break;
        }
        if (min_lv3 < min_lv2){
            min_lv2 = min_lv3;
            min_i = i;
            min_j = j;
        }
        i++;
    }
    return pair<int, int>(min_i, min_j);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }

    // Sort
    sort(arr, arr+N);

    long long int goal_min = INT64_MAX;

    vector<int> sol;

    for (int i=0; i<N-2; i++){
        auto [a, b] = search(i);
        long long int v = abs(arr[i] + arr[a] + arr[b]);
        if (v < goal_min){
            sol = {i, a, b};
            goal_min = v;
        }
    }
    
    cout << arr[sol[0]] << ' ' << arr[sol[1]] << ' ' << arr[sol[2]];

    return 0;
}