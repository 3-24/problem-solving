#include <bits/stdc++.h>

using namespace std;

int N;      // 1 <= N <= 1000000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    vector<int> v;

    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        auto j = upper_bound(v.begin(), v.end(), x);
        // cout << (int)(j - v.begin()) << '\n';
        while (j != v.begin() && *(j-1) == x){
            j--;
        }
        if (j == v.end()){
            v.push_back(x);
        } else {
            *j = x;
        }
    }

    cout << v.size();
    return 0;
}
