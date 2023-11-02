#include <bits/stdc++.h>

using namespace std;

struct color {
    int r,g,b,y,w;
};

void boardInit(color board[5][5]){
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            board[i][j] = {0,0,0,0,0};
        }
    }
}

color (*getInput(void))[4]{
    int value[4][4];

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cin >> value[i][j];
        }
    }

    char c;

    static color b[4][4];
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cin >> c;
            if (c == 'R') b[i][j] = {value[i][j],0,0,0,0};
            if (c == 'G') b[i][j] = {0,value[i][j],0,0,0};
            if (c == 'B') b[i][j] = {0,0,value[i][j],0,0};
            if (c == 'Y') b[i][j] = {0,0,0,value[i][j],0};
            if (c == 'W') b[i][j] = {0,0,0,0,value[i][j]};
        }
    }
    return b;
}

int main(){
    color board[5][5];
    color (*b)[4] = getInput();
    return 0;
}