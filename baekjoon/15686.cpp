#include <bits/stdc++.h>
using namespace std;
// 2 <= N <= 50
// 1 <= M <= 13
int N, M;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
stack<vector<int>> choice_q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int x;
            cin >> x;
            if (x == 2){
                chickens.push_back(pair<int, int>(i, j));
            }
            else if (x == 1) {
                houses.push_back(pair<int, int>(i, j));
            }
        }
    }

    choice_q.push(vector<int>());

    int min_cost = INT_MAX;
    
    while (choice_q.size() != 0){
        vector<int> plan = choice_q.top();
        choice_q.pop();
        if (plan.size() == M){
            int cost = 0;
            for (auto house: houses){
                int cost_local = INT_MAX;
                for (auto chicken_idx: plan){
                    pair<int, int> chicken = chickens[chicken_idx];
                    cost_local = min(cost_local, abs(house.first - chicken.first) + abs(house.second - chicken.second));
                }
                cost += cost_local;
            }
            min_cost = min(min_cost, cost);
        } else {
            int final_idx;
            if (plan.size() == 0){
                final_idx = -1;
            } else{
                final_idx = plan[plan.size()-1];
            }

            for (int i = final_idx+1; i<chickens.size(); i++){
                vector<int> new_plan = plan;
                new_plan.push_back(i);
                choice_q.push(new_plan);
            }
        }
    }

    cout << min_cost;

    return 0;
}