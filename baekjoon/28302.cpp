#include <bits/stdc++.h>

using namespace std;

char arr[2][1024];
int length[2];
// 1 a b: Merge ath and bth elements
// 2 a x y: Split ath element into color x and y
deque<vector<int>> op[2];
const char printer[3] = {'R', 'G' ,'B'};
map<char, int> C;

void merge(int arr_i, int i){
    if (arr_i == 0){
        op[arr_i].push_back(vector<int>{1, i, i+1});
    } else {
        op[arr_i].push_front(vector<int>{2, i, arr[arr_i][i], arr[arr_i][i+1]});
    }

    arr[arr_i][i] = 3 - arr[arr_i][i] - arr[arr_i][i+1];
    for (int j=i+1; j<length[arr_i]; j++){
        arr[arr_i][j] = arr[arr_i][j+1];
    }

    length[arr_i] -= 1;
}

void split(int arr_i, int i, int c1, int c2){
    if (arr_i == 0){
        op[arr_i].push_back(vector<int>{2, i, c1, c2});
    } else {
        op[arr_i].push_front(vector<int>{1, i, i+1});
    }

    length[arr_i] += 1;

    for (int j=i+1; j<length[arr_i]; j++){
        arr[arr_i][j+1] = arr[arr_i][j];
    }

    arr[arr_i][i] = c1;
    arr[arr_i][i+1] = c2;
}

void reduce(int arr_i){
    char *A = arr[arr_i];
    int l = length[arr_i];

    if (l == 1) return;
    
    // Ends with RG, GB, ..
    if (A[l-1] != A[l-2]){
        merge(arr_i, l-2);
        return reduce(arr_i);
    }

    // Ends with RR, GG, BB
    else {
        if (l == 2){
            // RR
            if (A[l-1] == 0){
                return;
            }
            else if (A[l-1] == 1){
                split(arr_i, l-1, 2, 0);
                merge(arr_i, 0);
            } else {
                split(arr_i, l-1, 1, 0);
                merge(arr_i, 0);
            }
            return;
        } else {
            // Ends with XYY where X != Y, then Reduce XY
            if (A[l-2] != A[l-3]){
                merge(arr_i, l-3);
                return reduce(arr_i);
            }
            // Ends with XXX, then split middle
            else {
                int color = A[l-1];
                split(arr_i, l-2, (color+1)%3, (color+2)%3);
                return reduce(arr_i);
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    C['R'] = 0;
    C['G'] = 1;
    C['B'] = 2;

    scanf("%d %s", &length[0], arr[0]);
    scanf("%d %s", &length[1], arr[1]);

    for (int i=0; i<length[0]; i++){
        arr[0][i] = C[arr[0][i]];
    }

    for (int i=0; i<length[1]; i++){
        arr[1][i] = C[arr[1][i]];
    }

    reduce(0);
    cout << '\n';
    reduce(1);

    if (length[0] != length[1]){
        cout << -1;
        return 0;
    }

    if (length[0] == 1){
        if (arr[0][0] != arr[1][0]){
            cout << -1;
            return 0;
        }
    }
    cout << op[0].size() + op[1].size() << '\n';
    for (vector<int> i: op[0]){
        if (i[0] == 1){
            cout << i[0] << ' ' << i[1]+1 << ' ' << i[2]+1;
        } else {
            cout << i[0] << ' ' << i[1]+1 << ' ' << printer[i[2]] << ' ' << printer[i[3]];
        }
        cout << '\n';
    }
    for (vector<int> i: op[1]){
        if (i[0] == 1){
            cout << i[0] << ' ' << i[1]+1 << ' ' << i[2]+1;
        } else {
            cout << i[0] << ' ' << i[1]+1 << ' ' << printer[i[2]] << ' ' << printer[i[3]];
        }
        cout << '\n';
    }
    return 0;
}