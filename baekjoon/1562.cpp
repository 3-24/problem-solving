#include <bits/stdc++.h>
using namespace std;

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000000

int dp[101][1 << 10][10];        // dp[i][j][k]는 i+1째 자리부터 N-1째 자리까지 사용하는 계단 수의 개수, j는 현재 사용한 수들을 의미 (비트마스킹), k는 i번째 자릿수
int n;

int do_dp(int depth, int used, int last_digit){
    if (dp[depth][used][last_digit]) return dp[depth][used][last_digit];
    if (depth == n-1) return 0;
    if (last_digit+1 != 10) dp[depth][used][last_digit] += do_dp(depth+1, used | (1 << (last_digit+1)), last_digit+1);
    if (last_digit-1 != -1) dp[depth][used][last_digit] += do_dp(depth+1, used | (1 << (last_digit-1)), last_digit-1);
    dp[depth][used][last_digit] %= MOD;
    return dp[depth][used][last_digit];
}


int main(){
    faster
    //test();
    scanf("%d", &n);

    for (int last_digit = 0; last_digit<10; last_digit++){
        dp[n-1][(1<<10) - 1][last_digit] = 1;
    }

    int sum = 0;
    for (int digit=1; digit<10; digit++){
        sum += do_dp(0, 1 << digit, digit);
        sum %= MOD;
    }
    printf("%d", sum);
    return 0;
}