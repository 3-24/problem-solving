#include <bits/stdc++.h>
using namespace std;

int nth[100000];

int main(){
    int n;
    cin >> n;
    n--;
    nth[0] = 666;
    int ind = 1;
    int lvind_end = 1;      // where lvlen digits index ends
    int lvlen = 3;
    while (n >= ind){
        for (int digit=1;digit<10;digit++){
            if (digit == 6){
                int lvind;
                for (lvind=0; lvind<lvind_end;lvind++){
                    if (nth[lvind] / (int)pow(10, lvlen-2) == 66) break;
                    nth[ind] = digit*pow(10,lvlen) + nth[lvind];
                    ind++;
                }
                for (int num = 0; num < pow(10,lvlen-2); num++){
                    nth[ind] = 666* pow(10, lvlen-2) + num;
                    ind++;
                }
                for (;lvind<lvind_end;lvind++){
                    if (nth[lvind] / (int)pow(10, lvlen-2) == 66) continue;
                    nth[ind] = digit*pow(10,lvlen) + nth[lvind];
                    ind++;
                }           
            }
            else{
                for (int lvind=0; lvind<lvind_end;lvind++){
                    nth[ind] = digit*pow(10,lvlen) + nth[lvind];
                    ind++;
                }
            }
        }
        lvind_end = ind;
        lvlen++;
    }
    cout << nth[n];
    return 0;
}