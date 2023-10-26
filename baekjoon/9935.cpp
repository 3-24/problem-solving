#include<bits/stdc++.h>
using namespace std;

char s[1000001];
char bomb[37];
int bomb_indices[1000001];

int main(){
    scanf("%s\n%s", s, bomb);
    int s_len = strlen(s);
    int bomb_len = strlen(bomb);
    int bomb_index = 0;
    int bomb_indices_index = 0;
    bool printed = false;
    for (int s_index=0; s_index<s_len; s_index++){
        if (s[s_index] == bomb[bomb_index]) bomb_indices[bomb_indices_index++] = bomb_index++;
        else if (s[s_index] == bomb[0]){
            bomb_indices[bomb_indices_index++] = 0;
            bomb_index = 1;
        }
        else {
            if (bomb_indices_index != 0){
                for (int i=0; i<bomb_indices_index; i++){
                    printf("%c", bomb[bomb_indices[i]]);
                }
                bomb_indices_index = 0;
                bomb_index = 0;
            }
            printf("%c", s[s_index]);
            printed = true;
            continue;
        }

        if (bomb_index == bomb_len){
            bomb_indices_index -= bomb_len;
            if (bomb_indices_index == 0) bomb_index = 0;
            else bomb_index = bomb_indices[bomb_indices_index-1]+1;
        }
    }

    if (bomb_indices_index != 0){
        for (int i=0; i<bomb_indices_index; i++){
            printf("%c", bomb[bomb_indices[i]]);
        }
        printed = true;
    }
    if (!printed) cout << "FRULA";
    cout << "\n";
    return 0;
}