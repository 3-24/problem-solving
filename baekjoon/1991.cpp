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

struct node {
    char value;
    node *left;
    node *right;
};

void print_nodes(vector<node *> v){
    for (auto n: v){
        putchar(n->value);
    }
    putchar('\n');
    return;
}


void dfs_preorder(node *v, vector<node *> *record){
    if (v == NULL) return;
    record->push_back(v);
    dfs_preorder(v->left, record);
    dfs_preorder(v->right, record);
    return;
}

void dfs_inorder(node *v, vector<node *> *record){
    if (v == NULL) return;
    dfs_inorder(v->left, record);
    record->push_back(v);
    dfs_inorder(v->right, record);
    return;
}

void dfs_postorder(node *v, vector<node *> *record){
    if (v == NULL) return;
    dfs_postorder(v->left, record);
    dfs_postorder(v->right, record);
    record->push_back(v);
    return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    faster
    int n;
    cin >> n;
    node nodes[n];
    node *root_node;
    for (int i=0; i<n; i++){
        char x, y, z;
        cin >> x >> y >> z;
        int xi = int(x) - 65;
        int yi = int(y) - 65;
        int zi = int(z) - 65;
        nodes[xi].value = x;
        debug(xi, yi, zi);
        if (yi != -19){
            nodes[xi].left = &(nodes[yi]);
        } else nodes[xi].left = NULL;
        if (zi != -19){
            nodes[xi].right = &(nodes[zi]);
        } else nodes[xi].right = NULL;

        if (x == 'A') root_node = &nodes[xi];
    }

    vector<node*> preorder, inorder, postorder;
    dfs_preorder(root_node, &preorder);
    print_nodes(preorder);
    dfs_inorder(root_node, &inorder);
    print_nodes(inorder);
    dfs_postorder(root_node, &postorder);
    print_nodes(postorder);
    return 0;
}