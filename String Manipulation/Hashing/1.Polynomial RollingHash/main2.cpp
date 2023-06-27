//given N string, length of each is M, find no of unique strings?
//complexity: O(N * M + N * log(N))
#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;
const int P = 137, mod = 1e9 + 7;

int pw[N];

void precal(){
    pw[0] = 1;
    for(int i = 1; i < N; i++){
        pw[i] = 1LL * pw[i - 1] * P % mod;
    }
}

int getHash(string s){
    int n = s.size();

    int hs = 0;
    for(int i = 0; i < n; i++){
        hs += 1LL * s[i] * pw[i] % mod;
        hs %= mod;
    }
return hs;
}

int main(){
    precal();

    int n; cin >> n; //no of string
    set<int> se;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        se.insert(getHash(s));
    }

    cout << se.size() << "\n";

return 0;
}