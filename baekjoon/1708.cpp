#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
};
typedef long long ll;

int N;
vector<Point> points;

bool cmp1(const Point &a, const Point &b){
    if (a.y == b.y){
        return (a.x < b.x);
    } else {
        return (a.y < b.y);
    }
}

ll ccw(const Point &a, const Point &b, const Point &c){
    ll v1x = b.x - a.x;
    ll v1y = b.y - a.y;
    ll v2x = c.x - a.x;
    ll v2y = c.y - a.y;

    return v1x * v2y - v1y * v2x;
}

int dist(const Point &a, const Point &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool cmp2(const Point &a, const Point &b){
    ll c = ccw(points[0], a, b);
    if (c == 0LL){
        return dist(points[0], a) < dist(points[0], b);
    } else {
        return (c < 0);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    sort(points.begin(), points.end(), cmp1);
    sort(++points.begin(), points.end(), cmp2);

    vector<int> st = {0, 1};

    for (int i=2; i<N; i++){
        while (true){
            if (st.size() < 2 || ccw(points[st[st.size()-2]], points[st[st.size()-1]], points[i]) < 0LL){
                st.push_back(i);
                break;
            } else {
                st.pop_back();
            }
        }
    }

    cout << st.size() << '\n';
    return 0;
}