#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point{
    ll x, y;

    Point operator-(Point &b){
        return Point(x - b.x, y - b.y);
    }
};

ll ccw(Point &a, Point &b, Point &c){
    Point v1 = b - a;
    Point v2 = c - a;
    return (v1.x * v2.y - v1.y * v2.x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int case_count = 0;
    while (true){
        case_count += 1;
        cin >> n;
        if (n == 0) break;
        vector<Point> points;
        for (int i=0; i<n; i++){
            ll x, y;
            cin >> x >> y;
            points.push_back(Point{x, y});
        }

        sort(points.begin(), points.end(), [](Point &a, Point &b){
            return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
        });

        vector<int> L, U;
        for (int i = 0; i < n; i++) {
            Point p = points[i];
            while(U.size() >= 2 && ccw(points[U[U.size() - 2]], points[U.back()], p) > 0) U.pop_back();
            while(L.size() >= 2 && ccw(points[L[L.size() - 2]], points[L.back()], p) < 0) L.pop_back();
            U.push_back(i);
            L.push_back(i);
        }
        
        vector<bool> visited(n, false);

        vector<int> convex_hull;

        for (int i: U){
            visited[i] = true;
            convex_hull.push_back(i);
        }

        for (int i=L.size()-1; i>=0; i--){
            int j = L[i];
            if (!visited[j]){
                visited[j] = true;
                convex_hull.push_back(j);
            }
        }

        double min_width = numeric_limits<double>::max();
        int k = convex_hull.size();

        for (int i=0; i<k; i++){
            int i1 = convex_hull[i];
            int i2 = convex_hull[(i+1) % k];
            Point vec = points[i2] - points[i1];
            double vec_norm = sqrt(vec.x * vec.x + vec.y * vec.y);
            double width = 0;
            for (int j=0; j<n; j++){
                Point vec2 = points[j] - points[i1];
                ll inner_prod = abs(vec.x * vec2.y - vec.y * vec2.x);
                double new_dist = inner_prod / vec_norm;
                width = max(width, new_dist);
            }
            min_width = min(width, min_width);
        }

        min_width = ceil(min_width * 100.0) / 100.0;

        cout << "Case " << case_count << ": " << fixed << setprecision(2) << min_width << '\n';
    }
    return 0;
}