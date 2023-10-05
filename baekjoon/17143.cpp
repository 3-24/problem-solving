#include <bits/stdc++.h>

using namespace std;

struct shark {
    int r;
    int c;
    int rs;
    int cs;
    int size;
    bool alive;
};

int R, C, M;

int fisher_catch(int fisher, deque<shark>& sharks){
    int min_r = INT_MAX;
    shark *sh = nullptr;
    for (auto& sh_iter: sharks){
        if (sh_iter.alive && fisher == sh_iter.c){
            if (min_r > sh_iter.r){
                min_r = sh_iter.r;
                sh = &sh_iter;
            }
        }
    }
    if (sh != nullptr){
        sh->alive = false;
        return sh->size;
    } else return 0;
}

void update_sharks(deque<shark>& sharks){
    map<pair<int, int>, shark *> pool;

    auto sh_it = sharks.begin();

    while (sh_it != sharks.end()){
        if (!sh_it->alive){
            sh_it = sharks.erase(sh_it);
        } else {
            int &r = sh_it->r;
            int &c = sh_it->c;

            r += sh_it->rs;
            c += sh_it->cs;

            while (r < 0 || r >= R){
                if (r < 0) r = -r;
                else r = 2*R - r - 2;
                sh_it->rs *= -1;
            }

            while (c < 0 || c >= C){
                if (c < 0) c = -c;
                else c = 2*C - c - 2;
                sh_it->cs *= -1;
            }

            auto key = pair<int, int> (r,c);

            if (pool.contains(key)){
                shark &dup_shark = *pool[key];
                if (dup_shark.size > sh_it->size){
                    sh_it->alive = false;
                } else {
                    dup_shark.alive = false;
                    pool[key] = &*sh_it;
                }
            } else {
                pool[key] = &*sh_it;
            }
            sh_it++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;

    deque<shark> sharks;

    while (M--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r -= 1;
        c -= 1;
        int rs = 0;
        int cs = 0;
        if (d == 1){
            rs = -s;
        } // UP
        else if (d == 2){
            rs = s;
        } // DOWN
        else if (d == 3){
            cs = s;
        } // RIGHT
        else cs = -s; // LEFT

        shark sh = {.r = r, .c = c, .rs = rs, .cs = cs, .size=z, .alive=true};
        sharks.push_back(sh);
    }

    int fisher = 0;
    int res = 0;

    while (true){
        res += fisher_catch(fisher, sharks);
        fisher++;
        if (fisher == C) break;
        update_sharks(sharks);
    }

    cout << res << '\n';

    return 0;
}