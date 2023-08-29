#include <bits/stdc++.h>

using namespace std;

array<int, 10> B;

int count_bits(int n){
    int count = 0;
    while (n != 0){
        if (n & 1) count += 1;
        n = (n >> 1);
    }
    return count;
}

void flip_line(array<int, 10> &arr, int flip, int row){
    for (int i=0; i<10; i++){
        if (flip & (1 << i)){
            arr[row] ^= (1 << i);
            if (i > 0) arr[row] ^= (1 << (i-1));
            if (i < 9) arr[row] ^= (1 << (i+1));
            if (row > 0) arr[row-1] ^= (1 << i);
            if (row < 9) arr[row+1] ^= (1 << i);
        }
    }
    return;
}

int main(){
    // Get 10x10 input
    for (int i=0; i<10; i++){
        string s;
        cin >> s;
        int n = 0;
        for (int j=0; j<10; j++){
            if (s[j] == 'O'){
                n += (1 << j);
            }
        }
        B[i] = n;
    }

    int min_count = INT_MAX;

    for (int n=0; n<(1<<10); n++){
        array<int, 10> B_ = B;
        int count = 0;

        for (int i=0; i<10; i++){
            int flip = (i > 0) ? B_[i-1] : n;
            count += count_bits(flip);
            flip_line(B_, flip, i);
            if (i > 0){
                assert(B_[i-1] == 0);
            }
        }
        if (B_[9] == 0){
            min_count = min(min_count, count);
        }
    }

    cout << (min_count == INT_MAX ? -1 : min_count);

}