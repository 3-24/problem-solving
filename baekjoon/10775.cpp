#include <bits/stdc++.h>

#define MAX_SIZE 100000

using namespace std;

int G, P;
int parent[MAX_SIZE+1];
int gi[MAX_SIZE];

int _find(int x){
    if (parent[x] < 0) return x;
    else {
        int y = _find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void _union(int x, int y){
    int xp = _find(x);
    int yp = _find(y);

    if (xp == yp) return;

    if (xp < yp){
        parent[yp] = xp;
    } else {
        parent[xp] = yp;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> G >> P;

    for (int g=0; g<=G; g++){
        parent[g] = -1;
    }

    for (int p=0; p<P; p++){
        cin >> gi[p];
    }

    int p;
    for (p=0; p<P; p++){
        int g = _find(gi[p]);
        if (g == 0){
            break;
        }
        _union(g, g-1);
    }
    cout << p;
}