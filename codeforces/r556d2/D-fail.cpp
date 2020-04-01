#include <bits/stdc++.h>
#include <string.h>
using namespace std;


int n,q;
string word;

struct religion {
    int ind = 0;
    int seq[251];
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char sign,alph;
    int re;

    cin >> n >> q;
    cin >> word;
    int wordCount[27] = {0};

    for (int i=0;i<n;i++){
        wordCount[(int) word[i] - 97] ++;
    }

    religion r[3];


    while(q--){
        cin >> sign;
        if (sign == '+'){
            cin >> re >> alph;
            re--;
            int alphAscii = (int)alph - 97;
            if (wordCount[alphAscii]){
                wordCount[alphAscii]--;
                r[re].seq[r[re].ind] = alphAscii;
                r[re].ind++;
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

        }
        else{
            cin >> re;
            re--;
            r[re].ind--;
            wordCount[r[re].seq[r[re].ind]]++;
            cout << "YES" << endl;
        }
    }

    return 0;
}