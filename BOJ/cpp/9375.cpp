#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n); // 0 <= n <= 30
        int result = 1;
        map<string,vector<string>> m;
        while(n--){
            string gear, part;
            cin >> gear >> part;
            m[part].push_back(gear);
        }
        map<string,vector<string>>::iterator iter;
        for (iter=m.begin();iter != m.end();iter++){
            result *= (*iter).second.size()+1;
        }
        printf("%d\n",result-1);
    }
}