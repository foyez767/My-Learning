//given two string, check if they are equal in O(1)
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
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
    string a, b; cin >> a >> b;

    if(getHash(a) == getHash(b)){
        cout << "They are equal\n";
    }
    else{
        cout << "They are different\n";
    }

return 0;
}