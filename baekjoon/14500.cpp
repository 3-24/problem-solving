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
    int n,m;
    cin >> n >> m;
    int arr[501][501];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int max_val = -1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m-3;j++){
            max_val = max(max_val, arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3]);
        }
    }

    debug(max_val);
    
    for (int j=0; j<m; j++){
        for (int i=0; i<n-3; i++){
            max_val = max(max_val, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j]);
        }
    }

    debug(max_val);
    
    for (int i=0; i<n; i++){
        for (int j=0;j<m-2; j++){
            int base = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            for (int k=0;k<3;k++){
                if (i > 0) max_val = max(max_val, base + arr[i-1][j+k]);
                if (i < n-1) max_val = max(max_val, base + arr[i+1][j+k]);
            }
        }
    }

    for (int j=0; j<m; j++){
        for (int i=0;i<n-2; i++){
            int base = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            for (int k=0;k<3;k++){
                if (j > 0) max_val = max(max_val, base + arr[i+k][j-1]);
                if (j < m-1) max_val = max(max_val, base + arr[i+k][j+1]);
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m-1; j++){
            int base = arr[i][j] + arr[i][j+1];
            if (i < n-1) max_val = max(max_val, arr[i+1][j] + arr[i+1][j+1] + base);
            if (i < n-1 && i > 0){
                max_val = max(max_val, base + arr[i-1][j] + arr[i+1][j+1]);
                max_val = max(max_val, base + arr[i-1][j+1] + arr[i+1][j]);
            }
        }
    }

    for (int j=1; j<m-1; j++){
        for (int i=0; i<n-1; i++){
            int base = arr[i][j] + arr[i+1][j];
            max_val = max(max_val, base + arr[i][j-1]  + arr[i+1][j+1]);
            max_val = max(max_val, base + arr[i+1][j-1] + arr[i][j+1]);
        }
    }

    cout << max_val;
    

    return 0;
}