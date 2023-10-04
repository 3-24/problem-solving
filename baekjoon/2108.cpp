#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> num(N, 0);
    map<int, int> count;
    int mean = 0;
    for (int i=0; i<N; i++){
        cin >> num[i];
        if (count.contains(num[i])){
            count[num[i]] += 1;
        } else {
            count[num[i]] = 1;
        }
        mean += num[i];
    }


    mean = (int)(round((float)mean / N));

    cout << mean << '\n';
    
    sort(num.begin(), num.end());
    
    cout << num[N >> 1] << '\n';
    
    vector<pair<int, int>> count_sort;
    for (auto [n, c]: count){
        count_sort.push_back({-c, n});
    }
    
    sort(count_sort.begin(), count_sort.end());

    if (N == 1) cout << num[0] << '\n';
    else {
        if (count_sort[0].first == count_sort[1].first){
            cout << count_sort[1].second << '\n';
        } else {
            cout << count_sort[0].second << '\n';
        }
    }

    cout << num[N-1] - num[0] << '\n';
}