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

    int n;
    int s;
    int arr[41];
    unordered_map<int, int> m1;

    void put1(int i, int sum){
        if (i == n/2){
            if (m1.contains(sum)) m1[sum] += 1;
            else m1[sum] = 1;
            return;
        }
        put1(i+1, sum);
        put1(i+1, sum+arr[i]);
    }

    ll eval2(int i, int sum){
        if (i == n){
            // sum + x = s -> x = s - sum
            if (m1.contains(s-sum)){
                debug(sum, s-sum);
                return m1[s-sum];
            }
            else return 0;
        } 
        else return eval2(i+1, sum) + eval2(i+1, sum+arr[i]);
    }

    int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    #endif
        faster
        cin >> n >> s;
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        put1(0, 0);

        cout << eval2(n/2, 0) + (s == 0 ? -1 : 0);


        return 0;
    }