#include <bits/stdc++.h>

#define MAX_STAR 30000

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

dim2 init_coord[MAX_STAR];
dim2 velocity[MAX_STAR];
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
ll max_dist(int day){
    vector<dim2> stars;
    for (int i=0; i<n; i++){
        stars.push_back({
            init_coord[i].x + day * velocity[i].x,
            init_coord[i].y + day * velocity[i].y
        });
    }

    // Convex Hull
    sort(stars.begin(), stars.end(), 
        [](dim2 &a, dim2 &b) {
            return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
    });

    sort(stars.begin()+1, stars.end(), 
    [&stars](dim2 &a, dim2 &b){
        ll c = ccw3(stars[0], a, b);
        if (c == 0) return (a.x < b.x);
        else return (c < 0);
    });

    vector<dim2> convex_stars = {stars[0], stars[1]};
    for (int i=2; i<n; i++){
        while (true){
            int l = convex_stars.size();
            if (l < 2 || ccw3(convex_stars[l-2], convex_stars[l-1], stars[i]) < 0){
                convex_stars.push_back(stars[i]);
                break;
            } else {
                convex_stars.pop_back();
            }
        }
    }

    // Rotating calipers
    ll res = 0;
    int i=0, j=1;
    const int l = convex_stars.size();
    for (int _t=0; _t < 2*l; _t++){
        int ni = (i+1) % l;
        int nj = (j+1) % l;
        ll c = ccw(convex_stars[ni] - convex_stars[i], convex_stars[nj] - convex_stars[j]);
        if (c >= 0) i = ni;
        if (c <= 0) j = nj;

        res = max(res, dist(convex_stars[i], convex_stars[j]));
    }
    // cout << day << ' ' << res << '\n';
    return res;
}

pair<ll, int> ternary_search(int start, int end){
    if (end - start < 3){
        ll res = LLONG_MAX;
        int index = -1;
        for (int i=start; i<=end; i++){
            ll d = max_dist(i);
            if (res > d){
                index = i;
                res = d;
            }
        }
        return {res, index};
    }
    
    int mid1 = (start * 2 + end) / 3;
    int mid2 = (start + end * 2) / 3;
    ll v1 = max_dist(mid1);
    ll v2 = max_dist(mid2);
    if (v1 > v2) return ternary_search(mid1, end);
    else return ternary_search(start, mid2);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> n >> t;
    for (int i=0; i<n; i++){
        ll x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        init_coord[i] = {x, y};
        velocity[i] = {dx, dy};
    }
    auto [value, day] = ternary_search(0, t);
    cout << day << '\n' << value << '\n';
}