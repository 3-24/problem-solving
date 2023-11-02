#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void _print_arr(const T x[], int size) {cerr << '{' ; for (int i=0; i<size; i++) cerr << x[i] << ((i == size-1) ? "" : ","); cerr << "}]" << '\n'; }


#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debug_arr(x,y) cerr << "[" << #x << "] = ["; _print_arr(x, y)
#else
#define debug(x...)
#define debug_arr(x, y)
#endif

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}
template<typename T>
bool exist_vector(vector<T> v, T x){return (find(v.begin(), v.end(), x) != v.end()) ? true : false;} // unsorted

struct linear_equation {
    int a;
    int b;
    int c;
};

int apply_linear_equation (linear_equation le, int x, int y){
    return le.a*x + le.b*y + le.c;
}

linear_equation find_linear_equation(int x0, int y0, int x1, int y1){
    linear_equation le = {y1-y0, x0-x1, y0*x1 - x0*y1};
    return le;
}

bool inside_rect(int x0, int y0, int x1, int y1, int x, int y){
    return (x0 <= x && x <= x1 && y0 <= y && y <= y1);
}

bool check_crossing(int x0, int y0, int x1, int y1, int a0, int b0, int a1, int b1){
    auto L1 = find_linear_equation(x0, y0, x1, y1);
    int val1 = apply_linear_equation(L1, a0, b0);
    int val2 = apply_linear_equation(L1, a1, b1);
    
    if ( (val1 < 0 && val2 < 0 ) || (val1 > 0 && val2 > 0)) return false;
    auto L2 = find_linear_equation(a0, b0, a1, b1);
    int val3 = apply_linear_equation(L2, x0, y0);
    int val4 = apply_linear_equation(L2, x1, y1);
    if ( (val3 < 0 && val4 < 0 ) || (val3 > 0 && val4 > 0)) return false;
    if ( (val3 | val4 | val1 | val2) == 0){
        // parallel
        int min_x = min(x0, x1);
        int max_x = max(x0, x1);
        int min_y = min(y0, y1);
        int max_y = max(y0, y1);
        if (!inside_rect(min_x,min_y,max_x,max_y, a0, b0) && !inside_rect(min_x,min_y,max_x,max_y, a1, b1)){
            return false;
        }
    }
    return true;
}

void solve(){
    int x0,y0,x1,y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int r1,r2,r3,r4;
    cin >> r1 >> r2 >> r3 >> r4;
    int rec_x0, rec_x1, rec_y0, rec_y1;
    rec_x0 = min(r1, r3);
    rec_x1 = max(r1, r3);
    rec_y0 = min(r2, r4);
    rec_y1 = max(r2, r4);
    bool p0_inside = false;
    bool p1_inside = false;
    if ( rec_x0 <= x0 && x0 <= rec_x1 && rec_y0 <= y0  && y0 <= rec_y1 ){
        p0_inside = true;
    }
    if ( rec_x0 <= x1 && x1 <= rec_x1 && rec_y0 <= y1  && y1 <= rec_y1 ){
        p1_inside = true;
    }

    if (p0_inside || p1_inside){
        debug(p0_inside, p1_inside);
        cout << "T\n";
        return;
    }
    
    vector<pair<int, int>> rec_points = {{rec_x0, rec_y0}, {rec_x1, rec_y0}, {rec_x1, rec_y1}, {rec_x0, rec_y1}};

    for (int i=0; i<4; i++){
        auto p1 = rec_points[i];
        auto p2 = rec_points[(i+1)%4];
        if (check_crossing(p1.first, p1.second, p2.first, p2.second, x0, y0, x1, y1)){
            debug(p1.first, p1.second, p2.first, p2.second, x0, y0, x1, y1);
            cout << "T\n";
            return;
        }
    }

    cout << "F\n";
    return;
}

int main(){
    faster
    int tn;
    cin >> tn;
    while (tn--){
        solve();
    }
    return 0;
}