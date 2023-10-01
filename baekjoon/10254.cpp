#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct dim2{
    ll x, y;
};

dim2 operator-(const dim2 &a, const dim2 &b){
    return dim2{
        a.x - b.x,
        a.y - b.y
    };
}

int n;

ll ccw(const dim2 &a, const dim2 &b){
    return (a.x * b.y - a.y * b.x);
}

ll ccw3(const dim2 &a, const dim2 &b, const dim2 &c){
    return ccw(b - a, c - a);
}

ll dist(const dim2 &a, const dim2 &b){
    dim2 diff = b - a;
    return (diff.x * diff.x + diff.y * diff.y);
}
// Rotating calipers algorithm
ll solve(vector<dim2> &coords){
    // Convex Hull
    sort(coords.begin(), coords.end(), 
        [](dim2 &a, dim2 &b) {
            return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
    });

    sort(coords.begin()+1, coords.end(), 
    [&coords](dim2 &a, dim2 &b){
        ll c = ccw3(coords[0], a, b);
        if (c == 0) return (a.x < b.x);
        else return (c < 0);
    });

    vector<dim2> convex_cities = {coords[0], coords[1]};
    for (int i=2; i<n; i++){
        while (true){
            int l = convex_cities.size();
            if (l < 2 || ccw3(convex_cities[l-2], convex_cities[l-1], coords[i]) <= 0){
                convex_cities.push_back(coords[i]);
                break;
            } else {
                convex_cities.pop_back();
            }
        }
    }

    // Rotating calipers
    ll res = 0;
    int i=0, j=1;
    int res_i, res_j;
    const int l = convex_cities.size();
    for (int _t=0; _t < 2*l; _t++){
        int ni = (i+1) % l;
        int nj = (j+1) % l;
        ll c = ccw(convex_cities[ni] - convex_cities[i], convex_cities[nj] - convex_cities[j]);
        if (c >= 0) i = ni;
        if (c <= 0) j = nj;

        ll d = dist(convex_cities[i], convex_cities[j]);
        if (res < d){
            res_i = i;
            res_j = j;
            res = d;
        }
    }

    cout << convex_cities[res_i].x << ' ' <<convex_cities[res_i].y << ' ' << convex_cities[res_j].x << ' ' << convex_cities[res_j].y << '\n';
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        vector<dim2> coords;
        for (int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            coords.push_back(dim2{x, y});
        }
        solve(coords);
    }
}