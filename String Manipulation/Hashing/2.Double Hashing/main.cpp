#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int P1 = 137, P2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int pw1[N], pw2[N];

void precal(){
    pw1[0] = 1;
    pw2[0] = 1;

    for(int i = 1; i < N; i++){
        pw1[i] = 1LL * pw1[i - 1] * P1 % mod1;
        pw2[i] = 1LL * pw2[i - 1] * P2 % mod2;
    }
}

pair<int,int> getHash(string s){
    int n = s.size();

    int hs1 = 0, hs2 = 0;

    for(int i = 0; i < n; i++){
        hs1 += 1LL * s[i] * pw1[i] % mod1;
        hs2 += 1LL * s[i] * pw2[i] % mod2;
        hs1 %= mod1;
        hs2 %= mod2;
    }
return {hs1, hs2};
}

int main(){
    precal();
    string a, b; cin >> a >> b;

    if(getHash(a) == getHash(b)) cout << "They are equal\n";
    else cout << "They are different\n";

return 0;
}