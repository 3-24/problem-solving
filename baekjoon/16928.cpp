#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> queue = {1};
    map<int, int> ladders;
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        ladders[x] = y;
    }

    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        ladders[u] = v;
    }

    int count = 0;
    while(true){
        vector<int> new_queue;
        set<int> new_set;
        count++;
        while(!queue.empty()){
            int x = queue.back();
            queue.pop_back();
            for (int j=1;j<=6;j++){
                int y = x+j;
                int new_element;
                while (ladders.find(y) != ladders.end()){
                    y = ladders[y];
                }
                new_element = y;
                if (new_element == 100){
                    goto end;
                }
                if (new_set.find(new_element) == new_set.end()){
                    new_set.insert(new_element);
                    new_queue.push_back(new_element);   
                }
            }
        }
        queue = new_queue;
    }
end:
    cout << count;

    return 0;
}