#include <algorithm>
#include <stdio.h>
#include <limits.h>

using namespace std;

int printpath(int ax,int ay,int bx,int by){
    for (int i=ax+1;i<=bx;i++){
        printf("%d %d\n",i,ay);
    }
    for (int i=ax-1;i>=bx;i--){
        printf("%d %d\n",i,ay);
    }

    for (int j=ay+1;j<=by;j++){
        printf("%d %d\n",bx,j);
    }
    for (int j=ay-1;j>=by;j--){
        printf("%d %d\n",bx,j);
    }
    return 0;
}

int main(){
    int xa,ya,xb,yb,xc,yc;
    scanf("%d %d",&xa,&ya);
    scanf("%d %d",&xb,&yb);
    scanf("%d %d",&xc,&yc);

    int x = INT_MAX;
    int sx,sy;

    for (int i=0;i<=1000;i++){
        for (int j=0;j<=1000;j++){
            int temp = 1 + abs(i-xa)+abs(i-xb)+abs(i-xc)+abs(j-ya)+abs(j-yb)+abs(j-yc);
            if (temp < x){
                x = temp;
                sx = i;
                sy = j;
            }
        }
    }
    printf("%d\n",x);
    printf("%d %d\n",sx,sy);
    printpath(sx,sy,xa,ya);
    printpath(sx,sy,xb,yb);
    printpath(sx,sy,xc,yc);
    return 0;

}