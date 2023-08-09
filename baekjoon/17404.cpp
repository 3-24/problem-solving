#include <bits/stdc++.h>

using namespace std;

int N;
int cost[1000][3];
// dp[i][c1][c2]는 0번째 집을 c1, i번째 집을 c2로 칠했을 때, 0~i번째 집을 칠하는 최소 비용
int dp[1000][3][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int i=0; i<N; i++){
        for (int c1 = 0; c1 < 3; c1++){
            for (int c2 = 0; c2 < 3; c2++){
                if (i == 0 && c1 == c2) dp[i][c1][c2] = cost[i][c1];
                else dp[i][c1][c2] = INT_MAX;
            }
        }
    }


    for (int i=1; i<N; i++){
        for (int c1=0; c1<3; c1++){
            for (int c2=0; c2<3; c2++){
                if (i == N-1 && c1 == c2) continue;
                for (int prev_color=0; prev_color<3; prev_color++){
                    if (prev_color == c2) continue;
                    if (dp[i-1][c1][prev_color] == INT_MAX) continue;
                    dp[i][c1][c2] = min(dp[i][c1][c2], dp[i-1][c1][prev_color] + cost[i][c2]);
                }
            }
        }
    }

    int o = INT_MAX;
    for (int c1=0; c1<3; c1++){
        for (int c2=0; c2<3; c2++){
            o = min(o, dp[N-1][c1][c2]);
        }
    }
    cout << o;
    return 0;
}