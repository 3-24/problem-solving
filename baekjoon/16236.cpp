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
    int n;
    cin >> n;
    int arr[21][21];
    int size = 2;
    int time[21][21];
    bool visited[21][21];
    memset(visited, 0, sizeof(bool)*21*21);
    array<int, 2> location;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int x;
            cin >> x;
            if (x == 9){
                arr[i][j] = 0;
                location = {i, j};
                time[i][j] = 0;
                visited[i][j] = true;
            }
            else arr[i][j] = x;
        }
    }

    int count = 0;
    int num_fish = 0;
    queue<array<int, 2>> q;
    q.push(location);
    int min_time = INT_MAX;
    int min_distance = INT_MAX;
    array<int, 2> next_location = location;
    while (!q.empty() || location != next_location){
        if (q.empty()){
            count += min_time;
            location = next_location;
            q = {};
            q.push(location);
            arr[location[0]][location[1]] = 0;
            time[location[0]][location[1]] = 0;
            memset(visited, false, sizeof(bool)*21*21);
            visited[location[0]][location[1]] = true;
            num_fish++;
            if (num_fish == size){
                size++;
                num_fish = 0;
            }
            min_time = INT_MAX;
            min_distance = INT_MAX;
#ifndef ONLINE_JUDGE
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    cerr << arr[i][j] << ' ';
                }
                cerr << '\n';          
            }
            cerr << "====================\n";
#endif
            continue;
        }
        array<int, 2> current = q.front();
        q.pop();
        array<int, 2> cand[4] = {{current[0]-1, current[1]}, {current[0], current[1]-1}, {current[0], current[1]+1}, {current[0]+1, current[1]}};
        for (int i=0; i<4; i++){
            array<int, 2> c = cand[i];
            if (c[0] >= 0 && c[0] < n && c[1] >= 0 && c[1] < n){
                if (visited[c[0]][c[1]]) continue;
                time[c[0]][c[1]] = time[current[0]][current[1]] + 1;
                visited[c[0]][c[1]] = true;
                if (size > arr[c[0]][c[1]] && arr[c[0]][c[1]] != 0){
                    int new_time = time[c[0]][c[1]];
                    int new_distance = abs(c[0] - location[0]) + abs(c[1] - location[1]);
                    if (new_time <= min_time && new_distance <= min_distance){
                        if (new_time == min_time && new_distance == min_distance){
                            if (c[0] < next_location[0] || (c[0] == next_location[0] && c[1] < next_location[1])){
                                next_location = c;
                            }
                        }
                        else {
                            next_location = c;
                            min_time = new_time;
                            min_distance = new_distance;
                        }
                    }
                }
                else if (size == arr[c[0]][c[1]] || arr[c[0]][c[1]] == 0){
                    q.push(c);
                }
            }
        }
    }

    cout << count;

    return 0;
}