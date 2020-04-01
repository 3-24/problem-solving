#include <bits/stdc++.h>

using namespace std;

bool visited[51][51];
bool map[51][51];


void dfs(int x, int y){
	vector <array<int,2>> plan;
	plan.push_back({x,y});

	searchList = {{1,0},{-1,0},{0,1},{0,-1}};

	while (!plan.empty()){
		int c[2] = plan.back();
		plan.pop_back();
		visited[c[0]][c[1]] = true;

		for (int i=0;i<4;i++){
			int new_x = c[0] + searchList[i][0], new_y = c[1] + searchList[i][1];
			if (0<= new_x && new_x < 51 && 0<= new_y && new_y < 51 ){
				if (!visited[new_x][new_y] && map[new_x][new_y]){
					plan.push_back({new_x,new_y});
				}
			}
		}

	}
}

int countMinWorm(){
	int m,n,k;
	memset(visited,false,sizeof(visited));
	memset(map,false,sizeof(map));

	int count = 0;

	while(k--){
		int x,y;
		cin >> x >> y;
		map[x][y] = true;
	}

	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (!visited[i][j] && map[i][j]){
				count++;
				dfs(i,j);
			}
		}
	}
	return count;
}

int main(){
	int t;
	while (t--){
		cout << countMinWorm() << endl;
	}
	return 0;
}
