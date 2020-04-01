#include <bits/stdc++.h>

using namespace std;

int stickers[100001][2];
int maxCost[100001][2];

void submain(){
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> stickers[i][0];
	}
	for (int i=0;i<n;i++){
		cin >> stickers[i][1];
	}

	maxCost[0][0] = stickers[0][0];
	maxCost[0][1] = stickers[0][1];
	maxCost[1][0] = max(stickers[1][0] + stickers[0][1], stickers[0][0]);
	maxCost[1][1] = max(stickers[1][1] + stickers[0][0], stickers[0][1]);

	for (int l=2;l<n;l++){
		maxCost[l][0] = max({stickers[l][0] + max ( maxCost[l-1][1], maxCost[l-2][1]), maxCost[l-1][0], maxCost[l-1][1]});
		maxCost[l][1] = max({stickers[l][1] + max ( maxCost[l-1][0], maxCost[l-2][0]), maxCost[l-1][0], maxCost[l-1][1] });
	}
	cout << max(maxCost[n-1][0], maxCost[n-1][1]) << endl;
	return;
}

int main(){
	int t;
	cin >> t;
	while (t--) submain();
	return 0;
}
