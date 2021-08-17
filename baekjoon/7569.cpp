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

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    faster
    int m, n, h;
    cin >> m >> n >> h;
    int arr[h][n][m];
    bool visited[h][n][m];
    int days[h][n][m];
    int remain = 0;
    queue<array<int, 3>> q;
    memset(visited, false, sizeof(bool)*h*n*m);

    for (int i=0; i<h; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<m; k++){
                cin >> arr[i][j][k];
                debug(arr[i][j][k]);
                if (arr[i][j][k] == 1){
                    visited[i][j][k] = true;
                    q.push({i, j, k});
                    days[i][j][k] = 0;
                }
                else if (arr[i][j][k] == 0){
                    remain++;
                }
            }
        }
    }
    int count = 0;
    while (!q.empty()){
        auto v = q.front();
        q.pop();
        debug(count, v, days[v[0]][v[1]][v[2]]);
        array<int, 3> cand[6] = {{v[0], v[1], v[2]-1}, {v[0], v[1], v[2]+1}, {v[0], v[1]-1, v[2]}, {v[0],v[1]+1, v[2]}, {v[0]-1, v[1], v[2]}, {v[0]+1, v[1], v[2]}};
        for (int i=0; i<6; i++){
            array<int, 3> c = cand[i];
            if (c[0] >= 0 && c[0] < h && c[1] >= 0 && c[1] < n && c[2] >= 0 && c[2] < m){
                if (arr[c[0]][c[1]][c[2]] == 0 && !visited[c[0]][c[1]][c[2]]){
                    q.push(c);
                    remain--;
                    visited[c[0]][c[1]][c[2]] = true;
                    days[c[0]][c[1]][c[2]] = days[v[0]][v[1]][v[2]] + 1;
                    count = max(count, days[c[0]][c[1]][c[2]]);
                }
                
            }
        }
    }

    if (remain != 0) cout << -1;
    else cout << count;

    return 0;
}