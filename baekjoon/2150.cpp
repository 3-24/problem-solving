#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> sccId;      // Component ID
vector<int> discovered; // Order of node visit
stack<int> st;
int sccCounter = 0;
int vertexCounter = 0;
int v;

int scc(int here){
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for (int there: adj[here]){
        if (discovered[there] == -1){
            ret = min(ret, scc(there));
        } else if (sccId[there] == -1){
            ret = min(ret, discovered[there]);
        }
    }

    if (ret == discovered[here]){
        while (true){
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here) break;
        }
        ++sccCounter;
    }
    return ret;
}

int main(){
    int e;
    cin >> v >> e;
    adj = vector<vector<int>>(v, vector<int>());
    sccId = vector<int>(v, -1);
    discovered = vector<int>(v, -1);

    for (int _1 = 0; _1 < e; _1++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        adj[a].push_back(b);
    }

    for (int i=0; i<v; i++){
        if (discovered[i] == -1) scc(i);
    }

    vector<vector<int>> sccSorted(sccCounter, vector<int>());
    vector<int> scc_map(sccCounter, -1);
    int sccSortedCounter = 0;
    for (int i=0; i<v; i++){
        int scc_id = sccId[i];
        if (scc_map[scc_id] == -1) scc_map[scc_id] = sccSortedCounter++;
        sccSorted[scc_map[scc_id]].push_back(i);
    }

    cout << sccCounter << '\n';

    for (auto sccUnit: sccSorted){
        for (int v: sccUnit){
            cout << v+1 << ' ';
        }
        cout << "-1\n";
    }
}