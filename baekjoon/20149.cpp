#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point{
    ll x, y;

    Point operator-(Point &p){
        return Point(x - p.x, y-p.y);
    }

    bool operator<(Point &p){
        return (x == p.x ? (y < p.y) : (x < p.x));
    }

    bool operator==(Point &p){
        return (x == p.x && y == p.y);
    }
};

ll det(ll a, ll b, ll c, ll d){
    return (a*d) - (b*c);
}

pair<ll, vector<vector<ll>>> matrix_inv(ll a, ll b, ll c, ll d){
    return {det(a, b, c, d), {{d, -b}, {-c, a}}};
}

vector<ll> mat_col_mult(vector<vector<ll>> &mat, vector<ll> col){
    assert(mat[0].size() == col.size());
    vector<ll> res(mat.size(), 0LL);
    for (int i=0; i< mat.size(); i++){
        for (int j=0; j<col.size(); j++){
            res[i] += mat[i][j] * col[j];
        }
    }
    return res;
}

ll ccw(Point &a, Point &b, Point &c){
    Point v1 = b - a;
    Point v2 = c - a;
    return det(v1.x, v1.y, v2.x, v2.y);
}

int sgn (ll x){
    return (0 < x) - (x < 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    Point p1{x1, y1}, p2{x2, y2}, p3{x3, y3}, p4{x4, y4};
    if (p2 < p1) swap(p1, p2);
    if (p4 < p3) swap(p3, p4);
    ll ccw1 = ccw(p1, p2, p3);
    ll ccw2 = ccw(p1, p2, p4);
    ll ccw3 = ccw(p3, p4, p1);
    ll ccw4 = ccw(p3, p4, p2);
    if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0){
        if (p2 < p3 || p4 < p1){
            cout << 0 << '\n';
        } else if (p2 == p3 || p4 == p1){
            cout << 1 << '\n';
            if (p2 == p3){
                cout << p2.x << ' ' << p2.y << '\n';
            } else {
                cout << p1.x << ' ' << p1.y << '\n';
            }
        } else {
            cout << 1 << '\n';
        }
    } else if (sgn(ccw1) * sgn(ccw2) == 1 || sgn(ccw3) * sgn(ccw4) == 1){
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
        auto [c1, mat1] = matrix_inv(p1.x, p1.y, p2.x, p2.y);
        vector<ll> t1 = mat_col_mult(mat1, {1, 1});
        ll a1 = t1[0];
        ll b1 = t1[1];

        auto [c2, mat2] = matrix_inv(p3.x, p3.y, p4.x, p4.y);
        vector<ll> t2 = mat_col_mult(mat2, {1, 1});
        ll a2 = t2[0];
        ll b2 = t2[1];

        auto [div_const, mat3] = matrix_inv(a1, b1, a2, b2);
        vector<ll> t3 = mat_col_mult(mat3, {c1, c2});
        ll x = t3[0];
        ll y = t3[1];
        cout << setprecision(17) << double(x) / div_const << ' ' << double(y) / div_const << '\n';
    }
}