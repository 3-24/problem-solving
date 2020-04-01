#include <bits/stdc++.h>

using namespace std;

const int MAX_N=25;
int n;
char buildings[MAX_N+1][MAX_N+1];
bool visited[MAX_N+1][MAX_N+1] = {false,};


pair<int,int> operator +(const pair<int,int> x, const pair<int,int> y){
    return make_pair(x.first+y.first, x.second+y.second);
}

bool validPoint(pair<int,int> x){
    int i = x.first, j= x.second;
    return (0<= i && i <n && 0<= j && j < n && !visited[i][j] && buildings[i][j] == '1');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int complex[MAX_N*MAX_N] = {0,};

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> buildings[i];
    }

    int n_complex = 0;
    pair <int,int> ways[4] = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (validPoint(make_pair(i,j))){
                n_complex++;
                queue <pair<int,int>> plan;
                plan.push(make_pair(i,j));

                while(!plan.empty()){
                    pair<int,int> s = plan.front();
                    plan.pop();
                    if (!visited[s.first][s.second]){
                        visited[s.first][s.second] = true;
                        complex[n_complex]++;

                        for (int k=0;k<4;k++){
                            pair<int,int> dest = s + ways[k];
                            if (validPoint(dest)){
                                plan.push(dest);
                            }
                        }
                    }

                }
            }
        }
    }

    cout << n_complex << endl;
    sort(complex,complex+n_complex+1);

    for (int i=1;i<=n_complex;i++){
        cout << complex[i] << endl;
    }

    return 0;
}
