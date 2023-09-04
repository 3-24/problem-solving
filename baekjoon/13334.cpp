#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int d;
    
    cin >> n;

    vector<pair<int, int>> segment_in;
    vector<pair<int, int>> segment;
    
    while (n--){
        int h, o;
        cin >> h >> o;
        if (h > o) swap(h, o);
        segment_in.push_back({h, o});
    }

    cin >> d;
    for (auto [h, o]: segment_in){
        if (o - h <= d){
            segment.push_back({o, h});
        }
    }

    sort(segment.begin(), segment.end());

    int i = -100000001;
    size_t max_count = 0;
    priority_queue<pair<int, int>> min_heap;

    for (auto [o, h]: segment){
        if (o > i){
            i = o;
            while (!min_heap.empty()){
                auto [nh1, o1] = min_heap.top();
                int h1 = -nh1;
                if (d < i - h1){
                    min_heap.pop();
                } else {
                    break;
                }
            }
        }
        min_heap.push({-h, o});
        max_count = max(max_count, min_heap.size());
    }

    cout << max_count;
}