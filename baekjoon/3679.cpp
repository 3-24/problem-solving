#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
    ll i, x, y;
};

bool operator<(Point &a, Point &b) {
    return (a.x == b.x ? (a.y < b.y) : (a.x < b.x));
}

int ccw(Point &a, Point &b, Point &c) {
    ll x1 = b.x - a.x;
    ll y1 = b.y - a.y;
    ll x2 = c.x - a.x;
    ll y2 = c.y - a.y;

    return (x1 * y2 - x2 * y1);
}

void solve() {
    int n;
    vector<Point> points;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back(Point(i, x, y));
    }

    swap(points[0], *min_element(points.begin(), points.end()));

    sort(points.begin() + 1, points.end(), [&points](Point &a, Point &b) {
        ll c = ccw(points[0], a, b);
        if (c == 0)
            return (a < b);
        else
            return (c > 0);
    });

    int pt = n - 1;
    for (int i = n - 1; i >= 1; i--) {
        if (ccw(points[0], points[i], points[i - 1]) == 0)
            pt--;
        else
            break;
    }
    reverse(points.begin() + pt, points.end());

    for (Point &p : points) {
        cout << p.i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        solve();
    }
}