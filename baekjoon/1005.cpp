#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000

int n,k,w; // buildings[1,1000], construction order[1,100000]
int buildCost[MAX_N+1];
int orderBuildCost[MAX_N+1];
vector<int> buildParent[MAX_N+1];

int calcBuildCost(int x){
    if (orderBuildCost[x] == -1) {
        if (buildParent[x].empty()) {
            orderBuildCost[x] = buildCost[x];
        }
        else {
            int compare_max = -1;

            for (auto i: buildParent[x]) {
                if (compare_max < calcBuildCost(i)) compare_max = calcBuildCost(i);
            }
            orderBuildCost[x] = compare_max + buildCost[x];
        }
    }
    return orderBuildCost[x];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // test cases
    cin >> t;
    while(t--){
        cin >> n >> k;
        //initialization
        memset(buildParent, {}, sizeof(vector<int>)*(MAX_N+1));
        memset(orderBuildCost,-1,sizeof(int)*(MAX_N+1));

        //get building costs
        for (int i=1;i<=n;i++){
            cin >> buildCost[i];
        }

        //get building order
        int primary,secondary;
        for (int i=0;i<k;i++){
            cin >> primary >> secondary;
            buildParent[secondary].push_back(primary);
        }

        //get target building
        cin >> w;

        cout << calcBuildCost(w) << endl;
    }

    return 0;
}