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

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
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

int room[51][51];
int upper_air_cleaner;
int r,c;

#ifndef ONLINE_JUDGE
void debug_room(){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cerr << room[i][j] << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
}
#endif

void update(){
    int room_change[r][c];
    memset(room_change, 0, sizeof(room_change));
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (room[i][j] != 0 && room[i][j] != -1){
                vector<pair<int, int>> cands = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
                int amount = room[i][j] / 5;
                for (pair<int, int> cand: cands){
                    if (!(0 <= cand.first && cand.first < r && 0 <= cand.second && cand.second < c)) continue;
                    if (room[cand.first][cand.second] == -1) continue;
                    room_change[cand.first][cand.second] += amount;
                    room_change[i][j] -= amount;
                }
            }
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            room[i][j] += room_change[i][j];
        }
    }
#ifndef ONLINE_JUDGE
    debug_room();
#endif
    int lower_air_cleaner = upper_air_cleaner+1;

    for (int i=upper_air_cleaner-1; i>0; i--){
        room[i][0] = room[i-1][0];
    }
    for (int j=0; j<c-1; j++){
        room[0][j] = room[0][j+1];
    }
    for (int i=0; i<upper_air_cleaner;i++){
        room[i][c-1] = room[i+1][c-1];
    }
    for (int j=c-1; j>=1; j--){
        if (j != 1) room[upper_air_cleaner][j] = room[upper_air_cleaner][j-1];
        else room[upper_air_cleaner][j] = 0;
    }
#ifndef ONLINE_JUDGE
    debug_room();
#endif
    for (int i=lower_air_cleaner+1;i<r-1;i++){
        room[i][0] = room[i+1][0];
    }

    for (int j=0; j<c-1; j++){
        room[r-1][j] = room[r-1][j+1];
    }

    for (int i=r-1; i >= lower_air_cleaner+1; i--){
        room[i][c-1] = room[i-1][c-1];
    }

    for (int j=c-1; j>=1; j--){
        if (j != 1) room[lower_air_cleaner][j] = room[lower_air_cleaner][j-1];
        else room[lower_air_cleaner][j] = 0;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    faster
    int t;
    cin >> r >> c >> t;
    bool _t = true;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> room[i][j];
            if (_t && room[i][j] == -1){
                upper_air_cleaner = i;
                _t = false;
            }
        }
    }
#ifndef ONLINE_JUDGE
    debug("start");
    debug_room();
#endif
    while (t--){
        update();
#ifndef ONLINE_JUDGE
    debug("update", t);
    debug_room();
#endif
    }
    int sum = 0;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (room[i][j] != -1) sum += room[i][j];
        }
    }
    cout << sum;
    return 0;
}