#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

#define N_MAX 500001

vector<int> child[N_MAX];
int in[N_MAX], out[N_MAX];
vector<i64> tr;

int N;
int N_ceil;

void dfs(int i){
    static int count = 0;
    in[i] = ++count;
    for (int j: child[i]){
        dfs(j);
    }
    out[i] = count;
}

i64 sum(int i){
    i64 ans = 0;
    while (i > 0){
        ans += (i64)tr[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int val){
    while (i <= N_ceil){
        tr[i] += (i64)val;
        i += (i & -i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> N >> M;


    int h = (int)ceil(log2(N));
    N_ceil = 1 << h;
    tr = vector<i64>(N_ceil+1, 0);

    vector<int> salary(N+1, 0);

    for (int i=1; i<=N; i++){
        cin >> salary[i];
        if (i > 1){
            int par;
            cin >> par;
            child[par].push_back(i);
        }
    }

    dfs(1);

    // Lazy propagation with Fanwick tr
    for (int t=0; t<M; t++){
        char kind;
        cin >> kind;
        if (kind == 'p'){
            int parent, amount;
            cin >> parent >> amount;
            for (int i: child[parent]){
                update(in[i], amount);
                update(out[i]+1, -amount);
            }
        } else {
            assert(kind == 'u');
            int i;
            cin >> i;
            cout << (i64)salary[i] + sum(in[i]) << '\n';
        }
    }
}
