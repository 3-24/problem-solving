#include <bits/stdc++.h>

using namespace std;

int I, N, K;
char stage[100][100];
vector<char> color;


// I번 - INK
int main(){
    cin >> I >> N >> K;
    cin.ignore();

    for (int i=0; i<I; i++){
        color.push_back(cin.get());
    }
    cin.ignore();

    int x, y;

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            stage[i][j] = cin.get();
            if (stage[i][j] == '@'){
                y = i;
                x = j;
            }
        }
        cin.ignore();
    }

    int ink_size = 0;
    int jump_count = 0;
    for (int i=0; i<K; i++){
        char c = cin.get();
        if (c == 'j') ink_size++;
        else if (c == 'U'){
            if (y > 0 && stage[y-1][x] == '.'){
                stage[y][x] = '.';
                stage[--y][x] = '@';
            }
        } else if (c == 'D'){
            if (y < N-1 && stage[y+1][x] == '.'){
                stage[y][x] = '.';
                stage[++y][x] = '@';
            }
        } else if (c == 'L'){
            if (x > 0 && stage[y][x-1] == '.'){
                stage[y][x] = '.';
                stage[y][--x] = '@';
            }
        } else if (c == 'R'){
            if (x < N-1 && stage[y][x+1] == '.'){
                stage[y][x] = '.';
                stage[y][++x] = '@';
            }
        } else {
            assert(c == 'J');
            char jump_color = color[jump_count++ % color.size()];
            for (int x_diff = -ink_size; x_diff <= ink_size; x_diff++){
                int y_range = ink_size - abs(x_diff);
                for (int y_diff = -y_range; y_diff <= y_range; y_diff++){
                    int x0 = x + x_diff;
                    int y0 = y + y_diff;
                    if (0<=x0 && x0 < N && 0<=y0 && y0 < N){
                        char &target = stage[y0][x0];
                        if (target != '.' && target != '@'){
                            target = jump_color;
                        }
                    }

                }
            }
            ink_size = 0;
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << stage[i][j];
        }
        cout << '\n';
    }
}