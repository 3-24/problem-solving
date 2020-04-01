#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
	    int a,b,c,d;
	    int x,y,x1,y1,x2,y2;
	    cin >> a >> b >> c >> d;
	    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	    int xf = x - a + b;
	    int yf = y - c + d;
	    if (x1 <= xf && xf <= x2 && y1 <= yf && yf <= y2){
		    if (a == b && x1 == x && x2 == x && a ) goto no;
		    if (c == d && y1 == y && y2 == y && c) goto no;
		    cout << "YES\n";
	    }
	    else{
no:
	    cout << "NO\n";
	    }
    }
    return 0;
}
