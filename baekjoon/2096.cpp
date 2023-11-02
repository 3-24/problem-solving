#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int problem[100001][3];

int min_or_max(int x, int y, bool is_min){
    return is_min ? min(x,y) : max(x,y);
}

array<int,3> update_dists(int level, int level_limit, bool is_min, array<int, 3> prev){
    if (level == level_limit) return prev;
    array<int, 3> new_dist;
    new_dist[0] = problem[level][0] + min_or_max(prev[0], prev[1], is_min);
    new_dist[1] = problem[level][1] + min_or_max(min_or_max(prev[0], prev[1], is_min), prev[2], is_min);
    new_dist[2] = problem[level][2] + min_or_max(prev[2], prev[1], is_min);
    return update_dists(level+1, level_limit, is_min, new_dist);
}

int main(){
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        problem[i][0] = x;
        problem[i][1] = y;
        problem[i][2] = z;
    }
    array<int, 3> min_dist = update_dists(0, n, true, array<int,3>{0,0,0});
    array<int, 3> max_dist = update_dists(0, n, false, array<int,3>{0,0,0});

    cout << *max_element(max_dist.begin(), max_dist.end()) << ' ' << *min_element(min_dist.begin(), min_dist.end());
    return 0;
}