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

// #Floyd-Warshall

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    faster
    int n, m;
    cin >> n >> m;
    int a,b,c;
    int arr[n+1][n+1];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INT_MAX;
        }
    }
    while(m--){
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    debug("init done");

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=1; k<=n; k++){
                if (arr[j][i] == INT_MAX || arr[i][k] == INT_MAX) {}
                else arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            debug(i, j, arr[i][j]);
            cout << (arr[i][j] == INT_MAX ? 0 : arr[i][j]) << ' '; 
        }
        cout << '\n';
    }
    return 0;
}